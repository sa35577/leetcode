class Solution {
public:
    bool backspaceCompare(string s, string t) {
        deque<int> d1,d2;
        for (char c : s) {
            if (c == '#') {
                if (!d1.empty()) d1.pop_back();
                
            }
            else d1.push_back(c);
        }

        for (char c : t) {
            if (c == '#') {
                if (!d2.empty()) d2.pop_back();
                
            }
            else d2.push_back(c);
        }
        if (d1.size() != d2.size()) return false;
        while (!d1.empty()) {
            char c = d1.front(), d = d2.front();
            if (c != d) return false;
            d1.pop_front();
            d2.pop_front();
        }
        return true;

    }
};