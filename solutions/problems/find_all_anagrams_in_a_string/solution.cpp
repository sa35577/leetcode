class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> res;
        int pfreq[26];
        int srem[26];
        memset(pfreq,0,sizeof(pfreq));
        memset(srem,0,sizeof(srem));
        for (char c : p) pfreq[c-'a']++;
        int badchars = 0;
        for (int i = 0; i < 26; i++) {
            srem[i] = pfreq[i];
            if (srem[i] > 0) badchars++;
        }
        for (int i = 0; i < p.size(); i++) {
            srem[s[i]-'a']--;
            if (srem[s[i]-'a'] == 0) badchars--;
            else if (srem[s[i]-'a'] == -1) badchars++;
        }
        if (badchars == 0) res.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            srem[s[i-p.size()]-'a']++;
            if (srem[s[i-p.size()]-'a'] == 0) badchars--;
            else if (srem[s[i-p.size()]-'a'] == 1) badchars++;
            
            srem[s[i]-'a']--;
            if (srem[s[i]-'a'] == 0) badchars--;
            else if (srem[s[i]-'a'] == -1) badchars++;
            
            if (badchars == 0) res.push_back(i-(p.size()-1));
        }
        return res;
    }
};