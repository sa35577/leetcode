#include <map>
class Solution {
public:
    map<int,int> mp;
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++) {
            int x = s[i]-'a';
            if (mp.find(x) == mp.end()) mp[x] = 1;
            else mp[x]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};