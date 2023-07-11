from ast import List
from cmath import inf
from functools import cache


class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        ans = 0
        @cache
        def dfs(i):
            if i == n-1:
                return 0
            ans = -inf
            for j in range(i+1,n,1):
                if -target <= nums[j] - nums[i] <= target:
                    ans = max(ans,dfs(j) + 1)
            return ans
        ans = dfs(0 )
        return -1 if ans < 0 else ans