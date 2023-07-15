O(n*2)
class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans = 0
        n = len(nums)
        for i in range(n):
            if nums[i] % 2 == 0:
                for j in range(i,n):
                    if (nums[j] - nums[i] + j - i) % 2 == 0 and nums[j] <= threshold:
                        ans = max(ans, j - i + 1)
                    else: break
        return ans
    
# O(n)
# 分组循环
class Solution:
    def longestAlternatingSubarray(self, a: List[int], threshold: int) -> int:
        ans, i, n = 0, 0, len(a)
        while i < n:
            if a[i] % 2 or a[i] > threshold:
                i += 1
            else:
                i0 = i
                i += 1
                while i < n and a[i] <= threshold and a[i] % 2 != a[i - 1] % 2:
                    i += 1  # i 是全局变量，二重循环 i+=1 至多执行 O(n) 次
                ans = max(ans, i - i0)
        return ans