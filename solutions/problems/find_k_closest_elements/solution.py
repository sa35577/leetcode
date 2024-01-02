class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        lst = []
        for i in arr:
            lst.append([abs(i-x),i])
        lst.sort()
        ret = []
        for i in range(k):
            ret.append(lst[i][1])
        ret.sort()
        return ret
        