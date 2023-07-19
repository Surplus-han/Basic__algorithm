class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        Sum = sum(nums)
        if Sum == 0:
            return 0
        last = -1
        ans = 1
        for i in range(len(nums)):
            if nums[i]:
                if last != -1:
                    ans*=i-last
                    ans %= 10**9+7
                last = i
        return ans