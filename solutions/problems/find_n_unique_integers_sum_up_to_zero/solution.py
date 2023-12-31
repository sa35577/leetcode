class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        lst = []
        if n % 2 == 1:
            lst.append(0)
            n -= 1
        for i in range(1,n/2+1,1):
            lst.append(i)
            lst.append(-i)
        return lst