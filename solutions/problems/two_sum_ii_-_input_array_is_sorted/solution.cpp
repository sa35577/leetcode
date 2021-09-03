#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> mp;
        vector<int> v(2);
        for (int i = 0; i < numbers.size(); i++) {
            mp[numbers[i]] = i+1;
        }
        for (int i = 0; i < numbers.size(); i++) {
            if (mp.find(target-numbers[i]) != mp.end()) {
                int v1 = i+1, v2 = mp[target-numbers[i]];
                if (v1 > v2) swap(v1,v2);
                v[0] = v1, v[1] = v2;
                return v;
            }
        }
        return v;
        
    }
};