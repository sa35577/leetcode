class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        L = 0
        R = -1
        curk = 0
        ans = 0
        while (R+1 < len(nums)) and (curk < k or nums[R+1] == 1):
            R += 1
            if nums[R] == 0:
                curk += 1
        if R+1 == len(nums):
            return R-L+1
        ans = max(ans,R-L+1)
        # print(L,R)

        while L < len(nums):
            if nums[L] == 0:
                curk -= 1
            L += 1
            while (R+1 < len(nums)) and (curk < k or nums[R+1] == 1):
                R += 1
                if nums[R] == 0:
                    curk += 1
            ans = max(ans,R-L+1)
            if R+1 == len(nums):
                break
            # print(L,R)
        return ans
        