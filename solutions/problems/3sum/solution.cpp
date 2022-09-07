class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int leftptr = 0;
        map<int,vector<pair<int,int>>> pairSums;
        vector<vector<int>> res;
        vector<int> uniques;
        while (leftptr < nums.size()) {
            int rightptr = leftptr;
            while (rightptr + 1 < nums.size() && nums[leftptr] == nums[rightptr+1]) ++rightptr;
            int val = nums[leftptr];
            if (pairSums.find(-val) != pairSums.end()) {
                vector<pair<int,int>> v = pairSums[-val];
                for (pair<int,int> p : v) {
                    vector<int> ele{val,p.first,p.second};
                    res.push_back(ele);
                }
            }
            if (leftptr != rightptr) {
                for (int i = 0; i < uniques.size(); i++) {
                    if (uniques[i] == -2 * val) {
                        vector<int> ele{val,val,uniques[i]};
                        res.push_back(ele);
                        break;
                    }
                    else if (uniques[i] > 0) break;
                }
                if (pairSums.find(2*val) == pairSums.end()) {
                    vector<pair<int,int>> v;
                    pairSums[2*val] = v;
                    
                }
                pairSums[2*val].push_back(make_pair(val,val));
            }
            if (rightptr - leftptr >= 2 && val == 0) {
                vector<int> ele{0,0,0};
                res.push_back(ele);
            }
            for (int i = 0; i < uniques.size(); i++) {
                pair<int,int> p = {uniques[i],val};
                if (pairSums.find(p.first + p.second) == pairSums.end()) {
                    vector<pair<int,int>> v;
                    pairSums[p.first + p.second] = v;
                    
                }
                pairSums[p.first + p.second].push_back(p);
                if (uniques[i] + val > 0) break;
            }
            uniques.push_back(val);
            leftptr = rightptr + 1;
            
        }
        return res;
    }
};