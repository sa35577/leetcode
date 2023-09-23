class Solution {
public:

    bool predecessor(string a, string b) {
        //checks if a is a direct predecessor of b
        if (a.size() != b.size()-1) return false;
        if (a == b.substr(0,a.size())) return true;
        if (a == b.substr(1)) return true;
        int L = 0, R = a.size()-1;
        while (L < a.size() && a[L] == b[L]) L++;
        while (R >= 0 && a[R] == b[R+1]) R--;
        if (a == "a") cout << L << " " << R << " " << a << " " << b << endl;
        return (L - R >= 1);
    }


    int longestStrChain(vector<string>& words) {
        vector<string> v[17];
        for (string w : words) {
            v[w.size()].push_back(w);
        }
        vector<int> vals[17];
        int mx = 1;
        for (int i = 1; i <= 16; i++) {
            //cout << i << endl;
            for (int j = 0; j < v[i].size(); j++) {
                string word = v[i][j];
                vals[i].push_back(1);
                for (int k = 0; k < v[i-1].size(); k++) {
                    if (predecessor(v[i-1][k],word)) {
                        vals[i].back() = max(vals[i].back(),vals[i-1][k] + 1);
                        mx = max(mx,vals[i].back());
                    }
                }
            }
        }
        return mx;
    }
};