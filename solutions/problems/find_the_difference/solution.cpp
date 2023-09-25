class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mp;
        for (char c : s) {
            if (mp.find(c) == mp.end()) mp[c] = 1;
            else mp[c]++;
        }
        for (char c : t) {
            if (mp.find(c) == mp.end() || mp[c] == 0) return c;
            else mp[c]--;
        }
        return '\n';
    }
};