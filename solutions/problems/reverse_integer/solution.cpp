class Solution {
public:
    bool isGreater(vector<int> v, vector<int> w) {
        if (v.size() < w.size()) return false;
        if (v.size() > w.size()) return true;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > w[i]) return true;
            if (v[i] < w[i]) return false;
        }
        return false;
    }
    int reverse(int x) {
        if (x == 0) return 0;
        if (x == INT_MIN) return 0;
        vector<int> dig;
        vector<int> mx{2,1,4,7,4,8,3,6,4,7};
        vector<int> mn{2,1,4,7,4,8,3,6,4,8};
        int y = x;
        if (x < 0) y = -x;
        while (y > 0) {
            dig.push_back(y % 10);
            y /= 10;
        }
        if (dig.size() == 10) {
            if (x > 0 && isGreater(dig,mx)) return 0;
            else if (x < 0 && isGreater(dig,mn)) return 0; 
        }
        int res = 0;
        for (int i : dig) {
            res = res * 10 + i;
        }
        if (x < 0) res = -res;
        return res;
        
    }
};