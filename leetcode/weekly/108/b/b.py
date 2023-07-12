# Ä£ÄâÌâ

class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        tmp = set(nums)
        for a,b in zip(moveFrom,moveTo):
            tmp.remove(a)
            tmp.add(b)
        return sorted(tmp)