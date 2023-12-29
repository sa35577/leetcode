class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            if k % 2 == 0:
                return nums[0]
            return -1
        if k == 0:
            return nums[0]
        best = -1
        for i in range(min(len(nums),k+1)):
            if i != k-1:
                best = max(best,nums[i])
        return best