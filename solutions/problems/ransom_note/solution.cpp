class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> freq;
        for (char c : ransomNote) {
            if (freq.find(c) == freq.end()) freq[c] = 1;
            else freq[c]++;
        }
        for (char c : magazine) {
            if (freq.find(c) != freq.end()) freq[c]--;
        }
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second > 0) return false;
        }
        return true;
    }
};