# Ë«Ö¸Õë + Set / Counter 
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        ans = left = 0
        cnt = Counter()
        for right,x in enumerate(nums):
            cnt[x]+=1
            while max(cnt)-min(cnt) > 2:
                y = nums[left]
                cnt[y]-=1
                if cnt[y] == 0:
                    del cnt[y]
                left+=1
            ans += right-left+1
        return ans