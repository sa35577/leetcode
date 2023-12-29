class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        t = [-1,-1,-1]
        for triplet in triplets:
            if triplet[0] <= target[0] and triplet[1] <= target[1] and triplet[2] <= target[2]:
                t[0] = max(t[0],triplet[0])
                t[1] = max(t[1],triplet[1])
                t[2] = max(t[2],triplet[2])
        return (t[0] == target[0] and t[1] == target[1] and t[2] == target[2])