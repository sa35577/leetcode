def calc(c: str):
        return ord(c) - ord('a')

class Solution:
    
    def partitionLabels(self, s: str) -> List[int]:
        freq = [0 for i in range(26)]
        use = [0 for i in range(26)]
        partitions = []
        for c in s:
            freq[calc(c)] += 1
        L = 0
        for i in range(len(s)):
            use[calc(s[i])] += 1
            invalid = False
            for j in range(26):
                if use[j] != 0 and use[j] != freq[j]:
                    invalid = True
                    break
            if not invalid:
                partitions.append(i-L+1)
                L = i+1
        return partitions


        