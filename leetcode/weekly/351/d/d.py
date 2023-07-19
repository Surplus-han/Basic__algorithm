class Solution:
    def survivedRobotsHealths(self, pos: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(pos)
        stack = []
        for i in sorted(range(n),key = lambda x:pos[x]):
            d = directions[i]
            if d == 'L':
                while len(stack) and healths[i]:
                    j = stack.pop()
                    if healths[i] == healths[j]:
                        healths[i] = healths[j] = 0
                        break
                    elif healths[i] > healths[j]:
                        healths[i]-=1
                        healths[j] = 0
                    else:
                        healths[i] = 0
                        healths[j]-=1
                        if healths[j]:
                            stack.append(j)
            else:
                stack.append(i)
        return [x for x in healths if x != 0]