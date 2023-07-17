# O(n)
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = Counter()
        for i in range(len(nums)):
            cnt[nums[i]] +=1 
        for i,x in enumerate(nums):
            if cnt[x] > n // 2:
                return x
        