class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split('.')
        v2 = version2.split('.')
        l1 = len(v1)
        l2 = len(v2)
        if l1 < l2:
            for i in range(l2-l1):
                v1.append('0')
        elif l1 > l2:
            for i in range(l1-l2):
                v2.append('0')
        for i in range(len(v1)):
            idx = 0
            while idx < len(v1[i]) and v1[i][idx] == '0':
                idx += 1
            v1[i] = v1[i][idx:]
            if v1[i] == '':
                v1[i] = '0'
            v1[i] = int(v1[i])
        for i in range(len(v2)):
            idx = 0
            while idx < len(v2[i]) and v2[i][idx] == '0':
                idx += 1
            v2[i] = v2[i][idx:]
            if v2[i] == '':
                v2[i] = '0'
            v2[i] = int(v2[i])
        for i in range(len(v1)):
            if v1[i] < v2[i]:
                return -1
            elif v1[i] > v2[i]:
                return 1
        return 0
            
        