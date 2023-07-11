"""
    
    
"""
class Solution:
    def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:
        nums = (nums1, nums2)
        @cache
        def dfs(i: int, j: int) -> int:
            if i == 0: return 1
            res = 1
            if nums1[i - 1] <= nums[j][i]:
                res = dfs(i - 1, 0) + 1
            if nums2[i - 1] <= nums[j][i]:
                res = max(res, dfs(i - 1, 1) + 1)
            return res
        return max(dfs(i, j) for j in range(2) for i in range(len(nums1)))