# 子数组问题
# https://leetcode.cn/contest/biweekly-contest-108/problems/longest-alternating-subarray/

# 分组循环模板

# 分组循环
# 外层循环，确定子数组的起点
# 内层循环，枚举子数组的右端点

#时间复杂度O(n)   
class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        ans = -1
        i = 0
        n = len(nums)
        while i < n - 1:
            if nums[i+1] - nums[i] != 1:
                i+=1
                continue
            i0 = i # 记录起点
            i+=1   # i 的含义变成了子数组的右端点
            while i < n and nums[i] == nums[i0 + (i-i0) % 2]: # 符合题意
                i+=1
            ans = max(ans,i-i0) # [i0,i)
            i-=1 # 本题特殊 3 4 3 4 5 4 5  3434 是一个子数组 4545 也是，有交集4，i需要回退1
        return ans

        