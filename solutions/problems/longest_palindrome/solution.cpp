class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int> mp;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i]-'a';
            if (mp.find(idx) == mp.end()) mp[idx] = 1;
            else mp[idx]++;
        }
        bool foundodd = false;
        int ln = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int freq = it->second;
            if (freq % 2 == 1 && !foundodd) {
                freq--;
                foundodd = true;
                ln += 1;
            }
            ln += freq - (freq % 2);
        }
        return ln;
    }
};