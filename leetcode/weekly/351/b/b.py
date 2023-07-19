# 枚举操作次数 k
# 问题变成 x = num1-num2*k
# 计算x能否分解成 k 个 2^i
# 比如 x == 9 1001  至少可以分解成两个（二进制中1的个数），至多可以分解成9个1
class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for k in count(1):
            x = num1-k*num2
            if x < k:return -1
            if k >= x.bit_count(): 
                return k