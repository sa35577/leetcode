class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int L = 0, R = arr.size()-1;
        while (L < R) {
            int mid = (L+R)/2;
            if (mid == 0) L = mid+1;
            else if (mid == arr.size()-1) R = mid-1;
            else if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if (arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) L = mid+1;
            else R = mid-1;
        }
        return L;
    }
};