from collections import deque
class Solution(object):
    def getNeighbours(self,y,x,m,n):
        neighbours = []
        if y-1 >= 0:
            neighbours.append([y-1,x])
        if x-1 >= 0:
            neighbours.append([y,x-1])
        if y+1 < m:
            neighbours.append([y+1,x])
        if x+1 < n:
            neighbours.append([y,x+1])
        return neighbours
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        q = deque()
        for i in range(len(board)):
            if board[i][0] == 'O':
                q.append([i,0])
                board[i][0] = 'XX'
            if board[i][-1] == 'O':
                q.append([i,n-1])
                board[i][-1] = 'XX'
        for j in range(len(board[0])):
            if board[0][j] == 'O':
                q.append([0,j])
                board[0][j] = 'XX'
            if board[-1][j] == 'O':
                q.append([m-1,j])
                board[-1][j] = 'XX'
        print(q)
        while len(q) != 0:
            y,x = q.popleft()
            ne = self.getNeighbours(y,x,m,n)
            for ny,nx in ne:
                if board[ny][nx] == 'O':
                    board[ny][nx] = 'XX'
                    q.append([ny,nx])
                    print(ny,nx)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'XX':
                    board[i][j] = 'O'
        return board