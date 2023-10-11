class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> indexes;
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums2[0]+nums1[i],i});
            indexes.push_back(0);
        }
        vector<vector<int>> ret;
        for (int rep = 0; rep < k; rep++) {
            if (pq.empty()) break;
            pair<int,int> p = pq.top();
            pq.pop();
            ret.push_back({nums1[p.second],nums2[indexes[p.second]]});
            indexes[p.second]++;
            if (indexes[p.second] < nums2.size()) {
                pq.push({nums2[indexes[p.second]]+nums1[p.second],p.second});
            }
        }
        return ret;
    }
};