class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> freq;
        for (string word : words) {
            if (freq.find(word) == freq.end()) {
                freq[word] = 1;
            }
            else freq[word]++;
        }
        int numStrings = 0;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            string s = it->first;
            string t = "";
            t += s[1];
            t += s[0];
            if (s == t) {
                int inc = it->second / 2;
                freq[s] -= 2*inc;
                numStrings += 2*inc;
            }
            else {
                if (freq.find(t) != freq.end()) {
                    int inc = min(freq[t],it->second);
                    numStrings += inc*2;
                    freq[t] -= inc;
                    freq[s] -= inc;
                }
            }
            
        }
        for (int i = 0; i < 26; i++) {
            char c = (char)((int)('a')+i);
            string s = "";
            s += c; s += c;
            if (freq.find(s) != freq.end() && freq[s] > 0) {
                numStrings++;
                return numStrings*2;
            }
        }
        return numStrings*2;
    }
};