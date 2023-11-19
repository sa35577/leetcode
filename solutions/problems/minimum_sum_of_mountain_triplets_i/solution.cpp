class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        vector<int> mnRight{nums[0]};
        vector<int> mnLeft{nums.back()};
        for (int i = 1; i < nums.size(); i++) {
            mnRight.push_back(min(mnRight.back(),nums[i]));
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            mnLeft.push_back(min(mnLeft.back(),nums[i]));
        }
        reverse(mnLeft.begin(),mnLeft.end());
        int result = INT_MAX;
        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] > mnRight[i-1] && nums[i] > mnLeft[i+1]) {
                result = min(result,nums[i] + mnRight[i-1] + mnLeft[i+1]);
            }
        }
        if (result == INT_MAX) return -1;
        return result;

        // misinterpreted: minimum sum of nums[i] + nums[j] + nums[k]: i < j < k and nums[i] < nums[j] < nums[k]
        // vector<pair<int,int>> data(3);
        // //pair<value,sum>
        // data[0].first = data[1].first = data[2].first = data[0].second = data[1].second = data[2].second = 1000;
        // for (int x : nums) {
        //     if (data[0].first == 1000) {
        //         data[0].first = x;
        //         data[0].second = x;
        //     }
        //     else if (data[1].first == 1000) {
        //         if (x > data[0].first && x < data[1].first) {
        //             data[1].first = x;
        //             data[1].second = x + data[0].second;
        //         }
        //         if (x < data[0].first) {
        //             data[0].first = x;
        //             data[0].second = x;
        //         }
        //     }
        //     else {
        //         if (x > data[1].first && x < data[2].first) {
        //             data[2].first = x;
        //             data[2].second = x + data[1].second;
        //         }
        //         if (x > data[0].first && x < data[1].first) {
        //             data[1].first = x;
        //             data[1].second = x + data[0].second;
        //         }
        //         if (x < data[0].first) {
        //             data[0].first = x;
        //             data[0].second = x;
        //         }
        //     }
        //     cout << data[0].first << " " << data[0].second << "\n";
        //     cout << data[1].first << " " << data[1].second << "\n";
        //     cout << data[2].first << " " << data[2].second << "\n";
        // }
        // if (data[2].second < 1000) return data[2].second;
        // return -1; 
    }
};