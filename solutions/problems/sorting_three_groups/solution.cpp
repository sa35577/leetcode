class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int minCost = nums.size();
        // cout << (-1 < nums.size()) << endl;
        for (int i = -1; i < (int)(nums.size()); i++) {
            for (int j = i; j < (int)(nums.size()); j++) {
                int cost = 0;
                for (int k = 0; k <= i; k++) {
                    if (nums[k] != 1) cost++;
                }
                for (int k = i+1; k <= j; k++) {
                    if (nums[k] != 2) cost++;
                }
                for (int k = j+1; k < nums.size(); k++) {
                    if (nums[k] != 3) cost++;
                }
                minCost = min(minCost,cost);
                // cout << i << " " << j << " " << cost << endl;
            }
        }    
        return minCost;
    }
};