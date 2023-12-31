class Solution(object):
    def maximalNetworkRank(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        deg = [0 for i in range(n)]
        adj = [[False for i in range(n)] for j in range(n)]
        for a,b in roads:
            deg[a] += 1
            deg[b] += 1
            adj[a][b] = True
            adj[b][a] = True
        maxNetworkRank = 0
        for i in range(n):
            for j in range(i):
                if adj[i][j]:
                    maxNetworkRank = max(maxNetworkRank,deg[i]+deg[j]-1)
                else:
                    maxNetworkRank = max(maxNetworkRank,deg[i]+deg[j])
        return maxNetworkRank
        