class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i,x in enumerate(nums,1):
            if n % i == 0:
                ans+=x*x
        return ans