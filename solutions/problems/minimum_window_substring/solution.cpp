class Solution {
public:
    string minWindow(string s, string t) {
        string u = t;
        t = s;
        s = u;
        // if (t.size() == s.size()) return t;
        if (t.size() < s.size()) return "";
        map<char,int> freq;
        for (char c : s) {
            if (freq.find(c) == freq.end()) freq[c] = 0;
            freq[c]++;
        }
        int req = s.size();
        int L = 0;
        int R = -1;
        pair<int,int> minWindow = {0,t.size()-1};
        map<char,int> mp;
        // cout << "here\n";
        // cout << s << " " << t << endl;
        while (req > 0) {
            // cout << req << endl;
            R++;
            if (mp.find(t[R]) == mp.end()) mp[t[R]] = 0;
            mp[t[R]]++;
            if (freq.find(t[R]) != freq.end() && freq[t[R]] >= mp[t[R]]) {
                req--;
            }
            if (R == t.size()) return "";
        }
        // cout << "here\n";
        while (L < R) {
            if (freq.find(t[L]) == freq.end() || freq[t[L]] < mp[t[L]]) {
                mp[t[L]]--;
                if (mp[t[L]] == 0) mp.erase(t[L]);
                L++;
            }
            else break;
            
        }
        minWindow = {L,R}; 
        // cout << "here\n";
        
        //condition, L and R are always essential characters at every point crossing line 34
        while (R < t.size()) {
            if (R == t.size()-1) break;
            bool done = false;
            while (true) {
                if (R+1 < t.size()) {
                    R++;
                    if (t[R] == t[L]) {
                        L++;
                        break;
                    }
                    else {
                        if (mp.find(t[R]) == mp.end()) mp[t[R]] = 0;
                        mp[t[R]]++;
                    }
                }
                else {
                    done = true;
                    break;
                }
            }
            if (done) break;

            while (L < R) {
                if (freq.find(t[L]) == freq.end() || freq[t[L]] < mp[t[L]]) {
                    mp[t[L]]--;
                    if (mp[t[L]] == 0) mp.erase(t[L]);
                    L++;
                }
                else break;
            }
            if (minWindow.second - minWindow.first + 1 > R - L + 1) {
                minWindow = {L,R};
            }

        }
        return t.substr(minWindow.first,minWindow.second - minWindow.first + 1);
    }
};