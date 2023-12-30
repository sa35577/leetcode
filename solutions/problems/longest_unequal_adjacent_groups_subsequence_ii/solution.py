def hamming(s,t):
    if len(s) != len(t):
        return False
    cnt = 0
    for i in range(len(s)):
        if s[i] != t[i]:
            cnt += 1
    return (cnt == 1)

class Solution(object):
    def getWordsInLongestSubsequence(self, n, words, groups):
        """
        :type n: int
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """

        dp = [[1,i] for i in range(n)]
        mx = 1
        for i in range(1,n):
            for j in range(0,i):
                if groups[i] != groups[j] and hamming(words[i],words[j]) and dp[j][0] + 1 > dp[i][0]:
                    dp[i][0] = dp[j][0] + 1
                    dp[i][1] = j
            mx = max(mx,dp[i][0])
        idx = 0
        for i in range(n):
            if dp[i][0] == mx:
                idx = i
                break
        res = []
        while dp[idx][1] != idx:
            res.append(words[idx])
            idx = dp[idx][1]
        res.append(words[idx])
        res = res[::-1]
        return res
        