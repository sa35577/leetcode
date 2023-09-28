class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //two sum: n^2 with map, update iteratively
        // 3 sum quuery answres if nums[i] can be combined with (nums[j], nums[k] where j and k are > i)
        //map<int,vector<pair<int,int>>> twoSum;
        //map<int,vector<pair<int,pair<int,int>>>> threeSum;
        map<int,int> freq;
        vector<int> nums2;
        for (int i : nums) {
            if (freq.find(i) == freq.end()) freq[i] = 0;
            freq[i]++;
            if (freq[i] <= 4) nums2.push_back(i);
        }
        nums = nums2;
        set<pair<long long,int>> st[201]; //set for {sum, index} [up to index]
        long long targ = (long long)(target);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) st[0].insert({nums[0],0});
            else {
                st[i] = st[i-1];
                st[i].insert({nums[i],i});
            }
        }

        set<vector<int>> res;

        for (int i = nums.size()-1; i >= 0; i--) {
            for (int j = i+1; j < nums.size(); j++) {
                // if (twoSum.find(nums[i] + nums[j]) == twoSum.end()) {
                //     vector<pair<int,int>> v;
                //     twoSum[nums[i] + nums[j]] = v;
                // }
                // twoSum[nums[i] + nums[j]].push_back({i,j});
                for (int k = 0; k < i; k++) {
                    long long obj = targ-((long long)(nums[i]) + (long long)(nums[j]) + (long long)(nums[k]));
                    int idx = k-1;
                    if (idx >= 0) {
                        auto it = st[idx].lower_bound({obj,INT_MIN});
                        auto it2 = st[idx].upper_bound({obj,INT_MAX});
                        it2--;
                        if (it != st[idx].end()) {
                            //printf("%d %d %d\n",k,i,j);
                            for (auto it3 = it; it3 != it2; it3++) {
                                pair<int,int> cur = *it3;
                                if (it3->first != obj) break;
                                vector<int> v{(int)(it3->first),nums[k],nums[i],nums[j]};
                                sort(v.begin(),v.end());
                                res.insert(v);
                            }
                            if (it2 != st[idx].end()) {
                                pair<int,int> cur = *it2;
                                if (it2->first == obj) {
                                    vector<int> v{(int)(it2->first),nums[k],nums[i],nums[j]};
                                    sort(v.begin(),v.end());
                                    res.insert(v);
                                }
                            }
                            
                        }

                    }
                }

            }
            

        }
        vector<vector<int>> vres;
        for (auto it = res.begin(); it != res.end(); it++) {
            vres.push_back(*it);
        }
        return vres;
    }
};