import copy

class Solution:
    def isPalindrome(self,s):
        t = s[::-1]
        return (s == t)
    def partition(self, s: str) -> List[List[str]]:
        print(s)
        palindromes = [[] for i in range(len(s))]
        dp = [[] for i in range(20)]
        for i in range(len(s)):
            for j in range(i+1):
                if self.isPalindrome(s[j:i+1]):
                    palindromes[j].append(i)

        dp[0] = [[]]

        

        for i in range(len(s)):
            # print(dp[i])
            for j in palindromes[i]:
                lst = copy.deepcopy(dp[i])
                for k in lst:
                    # print(s[i:j+1])
                    # k.append(s[i:j+1])
                    k.append(s[i:j+1])
                    # print(i,j+1,dp[j+1])
                    # print(k)
                    dp[j+1].append(k)
                    # print(i,j+1,dp[j+1])
                # for k in range(len(dp[i])):
                #     curlist = dp[i][k]
                #     curlist.append(s[i:j+1])
                #     dp[j+1].append(curlist)
            # print(dp[i])
        # print(dp)
        return dp[len(s)]