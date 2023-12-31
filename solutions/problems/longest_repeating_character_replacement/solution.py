def calc(c):
    return ord(c)-ord('A')
def rev(x):
    return chr(x+ord('A'))
class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if len(s) <= k+1:
            return len(s)
        
        # freq = [[] for i in range(26)]
        # for i in range(len(s)):
        #     freq[calc(s[i])].append(i)
        ans = 1
        for c in range(26):
            L = 0
            R = -1
            curk = 0
            # curidx = 0
            while L < len(s): # and curidx < len(freq[c]):
                if L == 0:
                    while (R+1 < len(s)) and ( (curk < k) or (s[R+1] == rev(c)) ):
                        R += 1
                        if s[R] != rev(c):
                            curk += 1
                    if R + 1 == len(s):
                        return len(s)
                    ans = max(ans,R-L+1)
                    if c == 1:
                        print(L,R)
                
                if s[L] != rev(c):
                    curk -= 1
                L += 1
                # if R == L-1:
                #     R = L
                while (R+1 < len(s)) and ( (curk < k) or (s[R+1] == rev(c)) ):
                    R += 1
                    if s[R] != rev(c):
                        curk += 1
                ans = max(ans,R-L+1)
                if c == 1:
                    print(L,R)
        return ans
