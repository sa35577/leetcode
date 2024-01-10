typedef long long ll;
class Solution {
public:
    int getFloorMedian(vector<int>& v) {
        int n = v.size();
        if (n % 2 == 1) {
            return v[n/2];
        }
        return (v[n/2] + v[n/2-1])/2;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        bool seen[100005];
        fill(seen,seen+100005,false);
        ll score = 0;
        int sz = arr.size();
        for (int idx = 0; idx < k; idx++) {
            int cur = idx;
            if (seen[cur]) continue;
            vector<int> indexes;
            bool firstTime = true;
            while (cur != idx || firstTime) {
                indexes.push_back(cur);
                seen[cur] = true;
                cur += k;
                if (cur >= sz) {
                    cur -= sz;
                }
                firstTime = false;
            }
            vector<int> v;
            for (int index : indexes) v.push_back(arr[index]);
            sort(v.begin(),v.end());
            int med = getFloorMedian(v);
            for (int x : v) {
                score += (ll)(abs(x - med));
            }

        }
        return score;
    }
};