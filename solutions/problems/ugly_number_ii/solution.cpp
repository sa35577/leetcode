class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        set<int> st;
        int cnt = 1;
        pq.push(1);
        int twobound = INT_MAX/2, threebound = INT_MAX/3, fivebound = INT_MAX/5;
        while (cnt != n) {
            int x = pq.top();
            pq.pop();
            if (st.count(x) == 0) {
                if (x < twobound) pq.push(x*2);
                if (x < threebound) pq.push(x*3);
                if (x < fivebound) pq.push(x*5);
                cnt++;
                st.insert(x);
            }
            //cout << cnt << " " << x << endl;
        }
        while (st.count(pq.top()) != 0) pq.pop();
        return pq.top();
    }
};