#include <string>
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        for (int i = 0; i <= (int)(haystack.size()) - (int)(needle.size()); i++) {
            bool valid = true;
            for (int j = 0; j < (int)(needle.size()); j++) {
                //cout << i << " " << j << " ";
                if (haystack[i+j] != needle[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return i;
        }
        return -1;
    }
};