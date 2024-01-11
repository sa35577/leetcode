class Solution {
public:
    int getOnes(int x) {
        int cnt = 0;
        while (x > 0) {
            if (x % 2 == 1) cnt++;
            x /= 2;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for (int x : arr) {
            v.push_back({getOnes(x),x});
        }
        sort(v.begin(),v.end());
        vector<int> res;
        for (pair<int,int> p : v) {
            res.push_back(p.second);
        }
        return res;
    
    }
};