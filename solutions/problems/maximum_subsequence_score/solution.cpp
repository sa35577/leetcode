class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long,int>> n2;
        vector<long long> n1;
        for (int i = 0; i < nums2.size(); i++) {
            n2.push_back({(long long)(nums2[i]),i});
            n1.push_back((long long)(nums1[i]));
            //cout << n2.back().first << " " << n2.back().second << endl;
        }
        sort(n2.begin(),n2.end());
        reverse(n2.begin(),n2.end());
        multiset<long long> mx;
        long long sum = 0;
        long long ret = 0;
        for (int i = 0; i < k; i++) {
            mx.insert(n1[n2[i].second]);
            sum += n1[n2[i].second];
        }
        ret = sum * n2[k-1].first;
        for (int i = k; i < n2.size(); i++) {
            long long nextVal = n1[n2[i].second];
            if (nextVal > *(mx.begin())) {
                sum -= *(mx.begin());
                sum += nextVal;
                mx.erase(mx.begin());
                mx.insert(nextVal);
                ret = max(ret,sum * n2[i].first);
            }
        }
        return ret;

    }
};