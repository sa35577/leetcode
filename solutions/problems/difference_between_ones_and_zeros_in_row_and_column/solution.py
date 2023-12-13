class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        diff = [[0 for i in range(len(grid[0]))] for j in range(len(grid))]
        row = [0 for i in range(len(grid))]
        col = [0 for i in range(len(grid[0]))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                row[i] += grid[i][j]
                col[j] += grid[i][j]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                diff[i][j] = row[i] + col[j] - (len(grid) - row[i]) - (len(grid[0]) - col[j])
        return diff

        