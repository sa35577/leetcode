class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> v(3);
        fill(v.begin(),v.end(),0);
        for (int x : stones) v[x%3]++;
        int mx = max(v[1],v[2]), mn = min(v[1],v[2]);
        if (mx == 0) return false;
        if (mn == 0) {
            if (mx <= 2) return false;
            return (v[0] % 2 == 1);
        }
        if (mx == mn) {
            //say mx = 3 >= 2
            // 1,1,2,1,2, there is a 2 remaining that neither can take and is currently bobs turn
            if (mx == 1) {
                return (v[0] % 2 == 0);
            } 
            else {
                return (v[0] % 2 == 0);
            }
        }
        if (mn == 1 && v[0] % 2 == 0) {
            return true;
        }
        if (mx-mn >= 2 ) return ((mx-mn != 2) || (mx-mn == 2 && v[0] % 2 == 0));
        return (v[0] % 2 == 0 && v[0] != 0);

    }
};