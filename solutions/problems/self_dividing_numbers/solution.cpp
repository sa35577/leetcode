class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            int j = i;
            bool good = true;
            while (j > 0) {
                if (j % 10 == 0 || i % (j % 10) != 0) {
                    good = false;
                    break;
                }
                j /= 10;
            }
            if (good) res.push_back(i);
        }
        return res;
    }
};