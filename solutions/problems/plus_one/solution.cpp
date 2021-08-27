class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size()-1;
        while (idx >= 0) {
            digits[idx]++;
            if (digits[idx] < 10) break;
            digits[idx] = 0;
            idx--;
        }
        if (idx < 0) digits.insert(digits.begin(),1);
        return digits;
    }
};