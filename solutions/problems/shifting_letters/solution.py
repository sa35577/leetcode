class Solution:
    def shift(self, s: str, shift: int) -> str: # shift one character string by shift amount "shift"
        oldAscii = ord(s) - ord('a')
        newAscii = (oldAscii + shift) % 26 + ord('a')
        return chr(newAscii)

    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        t = [s[i] for i in range(len(s))]
        shiftAmount = 0
        for i in range(len(s)-1,-1,-1):
            shiftAmount = (shiftAmount + shifts[i]) % 26
            t[i] = self.shift(s[i],shiftAmount)
        return "".join(t)
        