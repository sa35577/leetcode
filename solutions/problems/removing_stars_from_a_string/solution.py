from collections import deque
class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        d = deque()
        st = ""
        for i in range(len(s)):
            if s[i] != '*':
                d.append(s[i])
            else:
                d.pop()
        while len(d) > 0:
            st += d.popleft()
        return st

        