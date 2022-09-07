class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ss;
        int leftptr = 0, rightptr = leftptr, mx = 0;
        while (rightptr < s.size()) {
            if (ss.count(s[rightptr]) == 0) {
                mx = max(mx,rightptr-leftptr+1);
                ss.insert(s[rightptr++]);
            }
            else {
                while (s[leftptr] != s[rightptr]) {
                    ss.erase(s[leftptr++]);
                }
                ss.erase(s[leftptr++]);
                mx = max(mx,rightptr-leftptr+1);
                ss.insert(s[rightptr++]);
            }
            //printf("%d %d %d\n", leftptr, rightptr, mx);
        }
        return mx;
    }
};