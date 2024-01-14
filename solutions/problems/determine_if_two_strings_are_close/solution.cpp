class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> freq1(26);
        vector<int> freq2(26);
        fill(freq1.begin(),freq1.end(),0);
        fill(freq2.begin(),freq2.end(),0);
        for (char c : word1) {
            freq1[c-'a']++;
        }
        for (char c : word2) {
            freq2[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] > 0 && freq2[i] == 0) return false;
            if (freq2[i] > 0 && freq1[i] == 0) return false;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
        
    }
};