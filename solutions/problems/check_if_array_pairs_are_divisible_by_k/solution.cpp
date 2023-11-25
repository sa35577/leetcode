class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int freq[100005];
        for (int i = 0; i < 100005; i++) freq[i] = 0;
        int cnt = 0;
        for (int num : arr) {
            int m = ((num % k) + k) % k;
            if (m == 0) {
                if (freq[0] != 0) {
                    cnt--;
                    freq[0]--;
                }
                else {
                    cnt++;
                    freq[0]++;
                }
            }
            else if (freq[k - m] > 0) {
                freq[k-m]--;
                cnt--;
            }
            else {
                freq[m]++;
                cnt++;
            }
        }
        return (cnt == 0);
        // int n1 = -1, cnt1 = 0, n2 = -1, cnt2 = 0;
        // for (int num : arr) {
        //     int m = ((num % k) + k) % k;
        //     if (n1 == -1) {
        //         n1 = m;
        //         cnt1++;
        //     }
        //     else if (n1 == m) {
        //         cnt1++;
        //     }
        //     else if (n2 == -1) {
        //         n2 = m;
        //         cnt2++;
        //     }
        //     else if (n2 == m) {
        //         cnt2++;
        //     }
        //     else return false;
        // }
        // return (cnt1 == cnt2);
    }
};