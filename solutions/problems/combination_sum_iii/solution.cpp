class Solution {
public:
    vector<vector<int>> combo(int k, int n, int curVal) {
        //cout << k << " " << n << " " << curVal << endl;
        vector<vector<int>> ret;
        if (9 - curVal + 1 < k) return ret;
        if (k == 0) {
            if (n == 0) {
               //cout << curVal << endl;
                vector<int> v{};
                ret.push_back(v);
                return ret;
            }
            else return ret;
        }
        if (curVal >= 10) return ret;
        vector<vector<int>> ret1 = combo(k,n,curVal+1);
        vector<vector<int>> ret2 = combo(k-1,n-curVal,curVal+1);
        ret.insert(ret.end(),ret1.begin(),ret1.end());
        for (int i = 0; i < ret2.size(); i++) {
            ret2[i].push_back(curVal);
        }
        ret.insert(ret.end(),ret2.begin(),ret2.end());
        return ret;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        return combo(k,n,1);
    }
};