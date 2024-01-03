class Solution {
public:
    bool test(int mid, vector<int>& diff, int k) {
        int cnt = 0;
        int idx = 0,curSum = 0;
        while (idx < diff.size()) {
            curSum = diff[idx];
            while (idx < diff.size() && curSum < mid) {
                idx++;
                if (idx == diff.size()) break;
                curSum += diff[idx];
            }
            if (curSum < mid) break;
            cnt++;
            idx++;
        }
        return (cnt >= k-1);
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        vector<int> diff;
        int L = INT_MAX, R = INT_MAX;
        for (int i = 1; i < price.size(); i++) {
            diff.push_back(price[i]-price[i-1]);
            L = min(L,price[i]-price[i-1]);
        }
        R = price.back()-price[0];

        while (L+1 < R) {
            // cout << L << " " << R << endl;
            int mid = (L+R)/2;
            if (test(mid,diff,k)) {
                L = mid;
            }
            else {
                R = mid-1;
            }
            
        }
        if (test(R,diff,k)) return R;
        return L;
        
    }
};