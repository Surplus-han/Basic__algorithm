class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = Counter(nums)
        tmp = max(cnt.values())
        for num in nums:
            if cnt[num] == tmp:
                ans = num
        c1,c2 = 0,cnt[ans]
        for i,x in enumerate(nums):
            if x == ans:
                c1+=1
                c2-=1
            if c1 * 2 > i + 1 and c2 * 2 > n-i-1:return i
        return -1
