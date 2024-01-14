class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26);
        fill(freq.begin(),freq.end(),0);
        for (char c : s) {
            freq[c-'a']++;
        }
        int bad = 0;
        for (char c : t) {
            if (freq[c-'a'] == 0) {
                bad++;
            }
            else {
                freq[c-'a']--;
            }
        }
        return bad;
    }
};