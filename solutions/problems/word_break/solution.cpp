class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool getHere[301];
        getHere[0] = 1;
        for (int i = 1; i <= 300; i++) getHere[i] = 0;
        for (int i = 0; i < s.size(); i++) {
            //cout << i << " " << getHere[i] << "\n";
            if (getHere[i]) {
                for (string word : wordDict) {
                    if (i + word.size() <= s.size() && s.substr(i,word.size()) == word) {
                        getHere[i+word.size()] = true;
                    }
                }
            }
        }
        return getHere[s.size()];
    }
};