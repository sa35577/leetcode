class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";
        vector<int> freq(26);
        fill(freq.begin(),freq.end(),0);
        for (char c : s) {
            freq[c-'a']++;
        }
        for (char c : order) {
            for (int i = 0; i < freq[c-'a']; i++) {
                res += c;
            }
            freq[c-'a'] = 0;
        }
        for (int idx = 0; idx < 26; idx++) {
            char c = (char)('a' + idx);
            for (int i = 0; i < freq[idx]; i++) {
                res += c;
            }
        }
        return res;
    }
};