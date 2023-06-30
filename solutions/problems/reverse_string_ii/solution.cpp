class Solution {
public:
    
    void swapSection(string &s, int l, int r) {
        while (l <= r) {
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    
    string reverseStr(string s, int k) {
        int len = s.size();
        int L = 0;
        
        while (len > 0) {
            if (len >= 2*k) {
                swapSection(s,L,L+k-1);
                L = L + 2*k;
                len = len - 2*k;
            }
            else if (len < k) {
                swapSection(s,L,s.size()-1);
                len = 0;
            }
            else {
                swapSection(s,L,L+k-1);
                len = 0;
            }
        }
        return s;
    }
};