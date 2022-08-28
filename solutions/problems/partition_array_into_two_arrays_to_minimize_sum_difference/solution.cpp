class Solution {
public:
    vector<int> addElements(vector<int> v, int x) {
        vector<int> ret;
        for (int i : v) {
            ret.push_back(i + x);
        }
        return ret;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int sum = 0;
        for (int i : nums) sum += i;
        double halfsum = sum / 2.0;
        vector<vector<int>> possibleSumsLeft, possibleSumsRight;
        vector<int> zeroVector{0};
        possibleSumsLeft.push_back(zeroVector);
        possibleSumsRight.push_back(zeroVector);
        for (int i = 1; i <= n; i++) {
            possibleSumsLeft.push_back(addElements(possibleSumsLeft[i-1],nums[i-1]));
            possibleSumsRight.push_back(addElements(possibleSumsRight[i-1],nums[i-1+n]));
            for (int j = i-1; j > 0; j--) {
                vector<int> v1 = addElements(possibleSumsLeft[j-1],nums[i-1]);
                vector<int> v2 = addElements(possibleSumsRight[j-1],nums[i-1+n]);
                possibleSumsLeft[j].insert(possibleSumsLeft[j].end(),v1.begin(),v1.end());
                possibleSumsRight[j].insert(possibleSumsRight[j].end(),v2.begin(),v2.end());
            }
        }
        for (int i = 1; i <= n; i++) {
            sort(possibleSumsLeft[i].begin(),possibleSumsLeft[i].end());
            sort(possibleSumsRight[i].begin(),possibleSumsRight[i].end());
        }
        double mn = INT_MAX;
        for (int i = 0; i <= n; i++) {
            for (int j : possibleSumsLeft[i]) {
                int pos = std::lower_bound(possibleSumsRight[n-i].begin(),possibleSumsRight[n-i].end(),halfsum-j) - possibleSumsRight[n-i].begin();
                int sz = possibleSumsRight[n-i].size();
                if (pos >= sz) {
                    if (sz > 0) {
                        double res = halfsum-j-possibleSumsRight[n-i][pos-1];
                        if (res < 0) res = -res;
                        if (mn >= res) {
                            mn = res;
                        }
                    }
                }
                else {
                    double res = halfsum-j-possibleSumsRight[n-i][pos];
                    if (res < 0) res = -res;
                    if (mn >= res) {
                        mn = res;
                    }
                    if (pos != 0) {
                        double res2 = halfsum-j-possibleSumsRight[n-i][pos-1];
                        if (res2 < 0) res2 = -res2;
                        if (mn >= res2) {
                            mn = res2;
                        }
                    } 
                }
            }
        }
        //cout << mn << " " << halfsum << endl;
        return (int)(2 * mn);
        
        
    }
};