tmp = [bin(pow(5,i))[2:]  for i in range(7)]  
class Solution:
    def minimumBeautifulSubstrings(self, s: str) -> int:
        n = len(s)
        @cache
        def dfs(i):
            if i == n:
                return 0
            ans = inf
            for j in range(i+1,n+1):
                if s[i:j] in tmp:
                    ans = min(ans,dfs(j) + 1)
            return ans
        ans = dfs(0)
        return ans if ans < inf else -1