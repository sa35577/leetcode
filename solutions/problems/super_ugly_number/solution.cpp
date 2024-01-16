class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<int> st;
        st.insert(1);
        int cnt = 0;
        while (cnt < n) {
            int x = *(st.begin());
            st.erase(st.begin());
            cnt++;
            if (cnt == n) {return x;}
            for (int prime : primes) {
                if (INT_MAX/prime >= x && st.find(x * prime) == st.end()) {
                    if (cnt + st.size() < n || x * prime <= *(st.rbegin())) {
                        st.insert(x * prime);
                    }
                }
            }
        }
        return -1;
    }
};