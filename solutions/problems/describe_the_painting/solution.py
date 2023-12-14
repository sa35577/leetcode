class Solution(object):
    def splitPainting(self, segments):
        """
        :type segments: List[List[int]]
        :rtype: List[List[int]]
        """
        N = 100005
        xs = []
        for L, R, v in segments:
            xs.append(L)
            xs.append(R)
        xs = sorted(list(set(xs)))
        a = [0 for _ in range(N)]
        for L, R, v in segments:
            a[L] += v
            a[R] -= v
        for i in range(N - 1):
            a[i + 1] += a[i]
        result = []
        for i in range(len(xs) - 1):
            if a[xs[i]] != 0:
                result.append((xs[i], xs[i + 1], a[xs[i]]))
        return result