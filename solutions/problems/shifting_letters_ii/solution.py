class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        diff = [0 for _ in range(len(s)+1)]
        for start,end,direction in shifts:
            if direction == 1: # forward
                diff[start] += 1
                diff[end + 1] -= 1
            else: # backward
                diff[start] -= 1
                diff[end+1] += 1
        for i in range(1,len(diff)):
            diff[i] += diff[i-1]
        # print(diff)
        res = ""
        i = 0
        for character in s:
            oldAscii = ord(character) - ord('a')
            newAscii = (oldAscii + diff[i]) % 26 + ord('a')
            res += chr(newAscii)
            i += 1

        return res