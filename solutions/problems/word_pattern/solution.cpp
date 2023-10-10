class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        map<string,char> mp2;
        stringstream ss(s);
        string pat;
        int idx = 0;
        while (ss >> pat) {
            //cout << pat;
            if (idx == pattern.size()) return false;
            if (mp.find(pattern[idx]) != mp.end()) {
                if (mp2.find(pat) == mp2.end()) return false;
                if (mp2[pat] != pattern[idx] || mp[pattern[idx]] != pat) return false;
            }
            else {
                if (mp2.find(pat) != mp2.end()) return false;
                mp2[pat] = pattern[idx];
                mp[pattern[idx]] = pat;
            }
            idx++;
        }
        if (idx != pattern.size()) return false;
        return true;
    }
};