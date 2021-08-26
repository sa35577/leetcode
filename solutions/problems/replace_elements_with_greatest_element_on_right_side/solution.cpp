class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size());
        int mx = arr[arr.size()-1];
        res[arr.size()-1] = -1;
        for (int i = arr.size()-2; i >= 0; i--) {
            res[i] = mx;
            mx = max(mx,arr[i]);
        }
        return res;
    }
};