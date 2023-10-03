class Solution {
public:
    int countOdds(int low, int high) {
        if (high % 2 == 0) high--;
        if (low % 2 == 0) low++;
        if (low > high) return 0;
        if (low == high) return 1;
        return (high - low)/2 + 1;
    }
};