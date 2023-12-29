class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(cost) - sum(gas) > 0:
            return -1

        gasMinusCost = []
        indexes = []
        for i in range(len(cost)):
            gasMinusCost.append(gas[i] - cost[i])
            indexes.append(i)
        idx = 0

        while idx < 2*len(cost):
            while idx < 2*len(cost) and gasMinusCost[idx % len(cost)] <= 0:
                idx += 1
            if idx == 2*len(cost):
                break
            print(idx % len(cost))
            L = idx % len(cost)
            R = L
            
            curScore = gasMinusCost[L]
            while (R) != indexes[L] + len(cost) and curScore + gasMinusCost[(R+1) % len(cost)] >= 0:
                curScore += gasMinusCost[(R+1) % len(cost)]
                gasMinusCost[(R+1) % len(cost)] = 0
                indexes[(R+1) % len(cost)] = indexes[L]
                R += 1
            gasMinusCost[indexes[L]] = curScore
            print(L,R%len(cost),curScore,gasMinusCost[(R+1) % len(cost)])
            if (R) == indexes[L] + len(cost):
                return indexes[L]
            idx += 1 + (R-L) % len(cost)
        val = indexes[0]
        for i in range(len(indexes)):
            if indexes[i] != val:
                print(indexes[i])
                return -1
        return -val
