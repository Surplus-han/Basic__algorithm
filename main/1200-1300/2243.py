class Solution:
    def digitSum(self, s: str, k: int) -> str:
        n = len(s)
        while n > k:
            temp = ""
            for i in range(0,n,k):
                strs = s[i:i+k]
                num = 0
                for c in  strs:
                    num+=int(c)
                temp += str(num)
            s = temp
            n = len(s)
        return s