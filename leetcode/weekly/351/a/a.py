class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            for j in range(i+1,n):
                if gcd(int(str(nums[i])[0]),int(str(nums[j])[-1])) == 1:
                    ans+=1
        return ans