class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int arr[60];
        memset(arr,0,sizeof(arr));
        int sum = 0;
        for (int t : time) {
            sum += arr[(60 - (t % 60)) % 60];
            arr[t % 60]++;
        }
        return sum;
    }
};