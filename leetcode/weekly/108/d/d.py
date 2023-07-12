# Ã¶¾Ù
class Solution:
    def countBlackBlocks(self, m: int, n: int, coordinates: List[List[int]]) -> List[int]:
        s = set(map(tuple, coordinates))
        arr = [0] * 5
        vis = set()
        for x, y in coordinates:
            for i in range(max(x - 1, 0), min(x + 1, m - 1)):
                for j in range(max(y - 1, 0), min(y + 1, n - 1)):
                    if (i, j) not in vis:
                        vis.add((i, j))
                        cnt = ((i, j) in s) + ((i, j + 1) in s) + \
                              ((i + 1, j) in s) + ((i + 1, j + 1) in s)
                        arr[cnt] += 1
        arr[0] = (m - 1) * (n - 1) - len(vis)
        return arr
