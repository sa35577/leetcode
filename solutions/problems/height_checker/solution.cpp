class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        sort(arr.begin(),arr.end());
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != heights[i]) cnt++;
        }
        return cnt;
    }
};