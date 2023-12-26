from collections import deque
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0 for i in range(len(temperatures))]
        deck = deque()
        deckSize = 0
        for i in range(len(temperatures)):
            while deckSize > 0:
                if deck[-1][0] < temperatures[i]:
                    answer[deck[-1][1]] = i - deck[-1][1]
                    deck.pop()
                    deckSize -= 1
                else:
                    break
            deck.append([temperatures[i],i])
            deckSize += 1
        return answer


        