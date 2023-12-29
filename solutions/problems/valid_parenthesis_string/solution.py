class Solution:
    def checkValidString(self, s: str) -> bool:
        countLeft,countRight = 0,0
        stars = []
        lst = [s[i] for i in range(len(s))]
        for i in range(len(s)):
            c = s[i]
            if c == "(":
                countLeft += 1
            elif c == "*":
                stars.append(i)
            else:
                countRight += 1
        
        if abs(countLeft-countRight) > len(stars):
            return False
        
        starLeft,starRight = 0,0
        if countLeft > countRight:
            starRight += countLeft - countRight
            rem = len(stars) - starRight
            starLeft += int(rem/2)
            starRight += int(rem/2)
        elif countLeft < countRight:
            starLeft += countRight - countLeft
            rem = len(stars) - starLeft
            starLeft += int(rem/2)
            starRight += int(rem/2)
        else:
            rem = len(stars)
            starLeft += int(rem/2)
            starRight += int(rem/2)
        for i in range(starLeft):
            lst[stars[i]] = '('
        for i in range(-starRight,0):
            lst[stars[i]] = ')'
        
        netBracket = 0
        for c in lst:
            if c == "(":
                netBracket += 1
            elif c == ")":
                netBracket -= 1
                if netBracket < 0:
                    return False
        return (netBracket == 0)
