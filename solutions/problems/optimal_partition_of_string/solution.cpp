class Solution {
public:
    int partitionString(string s) {
        bitset<26> seen;
        int cnt = 1;
        for (char c : s) {
            if (seen[c - '0']) {
                cnt += 1;
                seen >>= 26;
                seen[c-'0'] = 1;

            }
            else seen[c - '0'] = 1;
        }
        return cnt;
    }
};