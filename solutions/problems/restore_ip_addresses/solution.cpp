class Solution {
public:
    bool validNumber(string s) {
        if (s.size() == 0) return false;
        if (s[0] == '0' && s.size() > 1) return false;
        //cout << s << endl;
        int x = stoi(s);
        return (0 <= x && x <= 255);
    }
    vector<string> validCombs(string sofar, int dots, string rem) {
        vector<string> v;
        if (dots == 0) {
            if (rem.size() <= 3 && validNumber(rem)) {
                string res = sofar + rem;
                v.push_back(res);
            }
        }
        else {
            int x = rem.size();
            for (int i = 1; i <= min(3,x); i++) {
                string nxt = rem.substr(0,i);
                if (validNumber(nxt)) {
                    vector<string> rec = validCombs(sofar+nxt+".",dots-1,rem.substr(i));
                    v.insert(v.end(),rec.begin(),rec.end());
                }
            }
        }
        return v;
    }
    vector<string> restoreIpAddresses(string s) {
        return validCombs("",3,s);
    }
};