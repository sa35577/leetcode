class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<long long> arr2;
        sort(arr.begin(),arr.end());
        for (int i : arr) {
            arr2.push_back((long long)(i));
        }
        long long mod = 1000000007LL;
        map<int,long long> mp;
        long long res = 0;
        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = 1;
            int j = 0, k = i-1;
            while (j <= k) {
                if (arr2[j] * arr2[k] == arr2[i]) {
                    if (arr2[j] != arr2[k]) mp[arr2[i]] += (2 * mp[arr2[j]] * mp[arr2[k]]) % mod;
                    else mp[arr2[i]] += (mp[arr2[j]] * mp[arr2[k]]) % mod;
                    mp[arr2[i]] %= mod;
                    j++;
                    k--;
                }
                else if (arr2[j] * arr2[k] > arr2[i]) k--;
                else j++;
            }
            
            res = (res + mp[arr2[i]]) % mod;
            cout << mp[arr2[i]] << "\n";
        }
        return res;
    }
};