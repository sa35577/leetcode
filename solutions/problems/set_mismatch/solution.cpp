class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(2);
        int freq[10005];
        memset(freq,0,sizeof(freq));
        for (int x : nums) {
            freq[x]++;
            if (freq[x] == 2) v[1] = x;
        }
        int idx = 1;
        while (true) {
            if (freq[idx] == 0) {
                v[0] = idx;
                break;
            }
            idx++;
        }
        swap(v[1],v[0]);
        return v;
    }
};