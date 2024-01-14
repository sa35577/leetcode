class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26);
        vector<int> freq2(26);
        fill(freq1.begin(),freq1.end(),0);
        fill(freq2.begin(),freq2.end(),0);
        for (char c : s) {
            freq1[c-'a']++;
        }
        for (char c : t) {
            freq2[c-'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt += abs(freq1[i] - freq2[i]);
        }
        return cnt;
    }
};