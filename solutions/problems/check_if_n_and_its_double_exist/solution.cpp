class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i]*2 == arr[j] || arr[j]*2 == arr[i]) return true;
            }
        }
        return false;
    }
};