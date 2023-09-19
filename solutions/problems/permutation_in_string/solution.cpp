class Solution {
public:
    bool veceq(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        else if (s1.size() == s2.size()) {
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            return (s1 == s2);
        }
        long long mod = 1000000007;
        long long hash[26];
        hash[0] = 1;
        for (int i = 1; i < 26; i++) {
            hash[i] = (hash[i-1] * 26) % mod;
        }
        long long s1hash = 0;
        vector<int> s1freq,s2freq;
        for (int i = 0; i < 26; i++) {
            s1freq.push_back(0);
            s2freq.push_back(0);
        }
        for (char c : s1) {
            s1hash = (s1hash + hash[c-'a']) % mod;
            s1freq[c-'a']++;
        }
        long long s2hash = 0;
        for (int i = 0; i < s1.size(); i++) {
            s2hash = (s2hash + hash[s2[i]-'a']) % mod;
            s2freq[s2[i]-'a']++;
        }
        if (s1hash == s2hash && veceq(s1freq,s2freq)) return true;
        for (int i = s1.size(); i < s2.size(); i++) {
            int prev = i - s1.size();
            //s1hash = (s1hash + hash[s1[i]-'a'] - hash[s1[prev]-'a'] + mod) % mod;
            s2hash = (s2hash + hash[s2[i]-'a'] - hash[s2[prev]-'a'] + mod) % mod;
            s2freq[s2[prev]-'a']--;
            s2freq[s2[i]-'a']++;
            if (s1hash == s2hash && veceq(s1freq,s2freq)) return true;
        }
        return false;

    }

};