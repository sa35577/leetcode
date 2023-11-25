class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> maxLeft{nums[0]},maxRight{nums.back()};
        vector<int> minLeft{nums[0]},minRight{nums.back()};
        for (int i = 1; i < nums.size(); i++) {
            maxLeft.push_back(max(maxLeft.back(),nums[i]));
            minLeft.push_back(min(minLeft.back(),nums[i]));
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            maxRight.push_back(max(maxRight.back(),nums[i]));
            minRight.push_back(min(minRight.back(),nums[i]));
        }
        reverse(maxRight.begin(),maxRight.end());
        reverse(minRight.begin(),minRight.end());
        // vector<int> v;
        for (int i = indexDifference; i < nums.size(); i++) {
            if (maxLeft[i-indexDifference] >= valueDifference + nums[i]) {
                int j = 0;
                while (true) {
                    if (maxLeft[i-indexDifference] == nums[j]) {
                        vector<int> v{j,i};
                        return v;
                    }
                    j++;
                }
            }
            if (nums[i] >= minLeft[i-indexDifference] + valueDifference) {
                int j = 0;
                while (true) {
                    if (minLeft[i-indexDifference] == nums[j]) {
                        vector<int> v{j,i};
                        return v;
                    }
                    j++;
                }
            }
        }
        for (int i = 0; i < (int)(nums.size()) - indexDifference; i++) {
            if (maxRight[i+indexDifference] >= valueDifference + nums[i]) {
                int j = nums.size()-1;
                while (true) {
                    if (maxRight[i+indexDifference] == nums[j]) {
                        vector<int> v{i,j};
                        return v;
                    }
                    j--;
                }
            }
            if (nums[i] >= minRight[i+indexDifference] + valueDifference) {
                int j = nums.size()-1;
                while (true) {
                    if (minRight[i+indexDifference] == nums[j]) {
                        vector<int> v{i,j};
                        return v;
                    }
                    j--;
                }
            }
        }
        vector<int> v{-1,-1};
        return v;
    }
};