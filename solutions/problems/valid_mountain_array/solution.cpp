class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int L = 0, R = arr.size()-1;
        while (L+1 < arr.size() && arr[L] < arr[L+1]) L++;
        while (R-1 >= 0 && arr[R] < arr[R-1]) R--;
        return (L == R && L > 0 && L < arr.size()-1);
    }
};