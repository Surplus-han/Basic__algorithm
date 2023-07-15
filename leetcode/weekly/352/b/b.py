# ÏßÐÔÉ¸
# MX = 10 ** 6 + 1
# primes = []
# is_prime = [True] * MX
# for i in range(2, MX):
#     if is_prime[i]:
#         primes.append(i)
#     for p in primes:
#         if i * p >= MX: break
#         is_prime[i * p] = False
#         if i % p == 0: break
MX = 10 ** 6 + 1
primes = []
is_prime = [True] * MX
for i in range(2, MX):
    if is_prime[i]:
        primes.append(i)
        for j in range(i * i, MX, i):
            is_prime[j] = False

class Solution:
    def findPrimePairs(self, n: int) -> List[List[int]]:
        ans = []
        for x in primes:
            y = n - x
            if y < x:
                break
            if is_prime[y]:
                ans.append([x, y])
        return ans



