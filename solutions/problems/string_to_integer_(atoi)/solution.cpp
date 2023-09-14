class Solution {
public:
    int myAtoi(string s) {
        vector<int> v;
        int idx = 0;
        while (idx < s.size() && s[idx] == ' ') idx++;
        bool neg = false;
        if (idx < s.size() && s[idx] == '-') {
            neg = true;
            idx++;
        }
        else if (idx < s.size() && s[idx] == '+') {
            neg = false;
            idx++;
        }
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            v.push_back(s[idx]-'0');
            idx++;
        }

        reverse(v.begin(),v.end());
        while (v.size() > 0 && v.back() == '0') v.pop_back();
        reverse(v.begin(),v.end());

        long long ans = 0;
        long long mx = (long long)(INT_MAX);
        long long mn = (long long)(INT_MIN);
        for (int i = 0; i < v.size(); i++) {
            ans = ans * 10;
            if (neg) ans = ans - v[i];
            else ans = ans + v[i];
            if (ans <= mn) return INT_MIN;
            if (ans >= mx) return INT_MAX;
        }
        return (int)(ans);
    } 
};