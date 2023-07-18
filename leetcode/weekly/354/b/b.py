# 由于子序列没有顺序要求，则可以对数组排序之后+双指针
class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        l = 0
        ans = 0
        for r,x in enumerate(nums):
            while x - nums[l] > 2 * k:
                l+=1
            ans = max(ans,r-l+1)
        return ans