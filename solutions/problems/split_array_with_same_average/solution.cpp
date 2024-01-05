class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        if (nums.size() == 1) return false;
        //average(A) = average(B)
        //(sum els in A)/(num els in A) = (sum els in B)/(num els in B)
        //(sum els in A)(num els in B) = (sum els in B)(num els in A)
        //(sum els in A)(num els in B) = (sum(nums) - (sum els in A))(num els in A)
        //(sum els in A)(size(nums)) = (sum(nums))(num els in A)
        //(sum els in A)/(num els in A) = (sum(nums))/(size(nums))
        //average(A) = average(nums)
        //when normalizing by subtracting avg(nums) from all, sum(A) = 0 = sum(nums)
        bool dp[31][300005];
        bool ndp[31][300005];
        memset(dp,0,sizeof(dp));
        memset(ndp,0,sizeof(ndp));
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        dp[0][0] = 1;
        ndp[0][0] = 1;
        int maxsum[31];
        memset(maxsum,0,sizeof(maxsum));
        // int totsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // totsum += nums[i];
            maxsum[i+1] = maxsum[i] + nums[i];
        }
        int curCount = 0;
        for (int x : nums) {
            curCount++;
            for (int k = 0; k < curCount; k++) {
                for (int i = 0; i <= maxsum[k]; i++) {
                    if (dp[k][i]) {
                        ndp[k+1][i+x] = 1;
                    }
                }
            }
            for (int k = 0; k <= curCount; k++) {
                for (int i = 0; i <= maxsum[k]; i++) {
                    dp[k][i] = ndp[k][i];
                    // if (curCount <= 2) cout << dp[k][i] << " ";
                }
                // if (curCount <= 2) cout << endl;
            }
            // if (curCount <= 2) cout << "----------" << endl;
        }
        for (int numElements = 1; numElements < nums.size(); numElements++) {
            int sumAll = maxsum[nums.size()];
            if ((sumAll * numElements) % nums.size() == 0) {
                int requiredSum = (sumAll * numElements) / nums.size();
                // cout << requiredSum << " " << numElements << endl;
                if (dp[numElements][requiredSum]) return true;
            }
        }
        return false;
        
    }
};