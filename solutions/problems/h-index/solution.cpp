class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        reverse(citations.begin(),citations.end());
        int mx = -1;
        if (citations[0] == 0) return 0;
        for (int i = 1; i < citations.size(); i++) {
            if (citations[i-1] >= i && citations[i] <= i) mx = max(mx,i);
        }
        if (citations.back() >= citations.size()) return citations.size();
        return mx;
    }
};