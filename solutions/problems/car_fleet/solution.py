class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        data = [[position[i],speed[i]] for i in range(len(position))]
        data.sort()
        numFleets = 0
        idx = len(position)-1
        while idx >= 0:
            numFleets += 1
            frontTime = (target - data[idx][0])/data[idx][1]
            L = idx
            while L-1 >= 0:
                if (target - data[L-1][0])/data[L-1][1] <= frontTime:
                    L -= 1
                else:
                    break
            idx = L-1
        return numFleets