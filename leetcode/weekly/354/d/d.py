# 双指针+移动l的时候，反向判断
# word = "cbaaaabc", forbidden = ["aaa","cb"]
# l 指向b,r 指向 第三个a 的时候
# 由于包含aaa,r需要像右移，l需要,从r位置开始，向左，最长且不在f里的子串的左边界的位置

class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        fb = set(forbidden)
        ans = left = 0
        for right in range(len(word)):
            for i in range(right, max(right - 10, left - 1), -1):
                if word[i: right + 1] in fb:
                    left = i + 1
                    break
            ans = max(ans, right - left + 1)
        return ans
