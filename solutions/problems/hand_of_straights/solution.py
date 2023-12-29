class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        vals = {}
        for i in hand:
            if i not in vals:
                vals[i] = 1
            else:
                vals[i] = vals[i] + 1
        
        for i in hand:
            if vals[i] != 0:
                for j in range(groupSize):
                    if (i+j not in vals) or (vals[i+j] == 0):
                        return False
                    else:
                        vals[i+j] -= 1
        for i in hand:
            if vals[i] != 0:
                return False
        return True