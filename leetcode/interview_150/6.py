# 对于Z字行排列来说，
# 行数等于3的时候，打印字符串顺序是：123 2 123 2 123 2 123 ... 
#  1,3 位置会使遍历顺序相反，所以可用一个nums大小的数组，当数组索引i为边界值的时候使遍历顺序反过来
# 具体可以用一个flag,初始化成-1，i== 0 or i == 2,flag = -falg  这样 i+flag 相反

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        ans = ["" for _ in range(numRows)]
        i,flag = 0,-1
        for c in s:
            ans[i]+=c
            if i == 0 or i == numRows - 1:
                flag = -flag
            i+=flag
        return "".join(ans)        