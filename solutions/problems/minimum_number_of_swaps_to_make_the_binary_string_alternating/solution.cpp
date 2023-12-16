class Solution {
public:
    int minSwaps(string s) {
        int count1 = 0, count0 = 0;
        for (char c : s) {
            if (c == '1') count1++;
            else count0++;
        }
        if (abs(count1-count0) >= 2) return -1;
        if (count1 == count0) {
            int oneEven = 0;
            for (int i = 0; i < s.size(); i += 2) {
                if (s[i] == '1') oneEven++;
            }
            int oneOdd = (int)(s.size())/2 - oneEven;
            return min(oneEven,oneOdd);
        }
        else if (count1 > count0) {
            // 1 0 1 .... 0 1
            int oddZero = 0;
            for (int i = 1; i < s.size(); i += 2) {
                if (s[i] == '0') oddZero++;
            }
            return (int)(s.size())/2 - oddZero;
        }
        else {
            // 0 1 0 .... 1 0
            int oddOne = 0;
            for (int i = 1; i < s.size(); i += 2) {
                if (s[i] == '1') oddOne++;
            }
            return (int)(s.size())/2 - oddOne;
        }
        return -1;
    }
};