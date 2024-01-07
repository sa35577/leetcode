class Solution {
public:
    bool test(vector<int>& citations, int h) {
        int cnt = 0;
        for (int x : citations) {
            if (x >= h) cnt++;
        }
        return cnt >= h;
    }
    int hIndex(vector<int>& citations) {
        int L = 0, R = citations.size();
        while (L+1 < R) {
            int mid = (L+R)/2;
            if (test(citations,mid)) L = mid;
            else R = mid-1;
        }
        if (test(citations,R)) return R;
        return L;
    }
};