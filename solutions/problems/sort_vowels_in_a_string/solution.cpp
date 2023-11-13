class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        map<int,char> mp2;
        mp['A'] = 0;
        mp['E'] = 1;
        mp['I'] = 2;
        mp['O'] = 3;
        mp['U'] = 4;
        mp['a'] = 5;
        mp['e'] = 6;
        mp['i'] = 7;
        mp['o'] = 8;
        mp['u'] = 9;
        int freq[10];
        memset(freq,0,sizeof(freq));
        for (char c : s) {
            if (mp.find(c) != mp.end()) {
                freq[mp[c]]++;
            }
        }
        for (int i = 0; i < 10; i++) cout << freq[i] << endl;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            mp2[it->second] = it->first;
        }
        int idx = 0;
        string t = "";
        for (char c : s) {
            if (mp.find(c) == mp.end()) t += c;
            else {
                while (freq[idx] == 0) idx++;
                t += mp2[idx];
                freq[idx]--;
            }

        }
        return t;
    }
};