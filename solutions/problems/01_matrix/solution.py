from Queue import Queue

class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        q = Queue()
        dist = [[100000 for i in range(len(mat[0]))] for j in range(len(mat))]
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 0:
                    q.put([i,j,0])
                    dist[i][j] = 0
        
        while not q.empty():
            y, x, mindist = q.get()
            if dist[y][x] == mindist:
                if x-1 >= 0:
                    if dist[y][x-1] > mindist+1:
                        q.put([y,x-1,mindist+1])
                        dist[y][x-1] = mindist+1
                if x+1 < len(dist[0]):
                    if dist[y][x+1] > mindist+1:
                        q.put([y,x+1,mindist+1])
                        dist[y][x+1] = mindist+1
                
                if y-1 >= 0:
                    if dist[y-1][x] > mindist+1:
                        q.put([y-1,x,mindist+1])
                        dist[y-1][x] = mindist+1
                if y+1 < len(dist):
                    if dist[y+1][x] > mindist+1:
                        q.put([y+1,x,mindist+1])
                        dist[y+1][x] = mindist+1
        return dist