class Solution {
public:
    vector<int> getNext(vector<int> prev) {
        vector<int> nxt;
        nxt.push_back(1);
        for (int i = 1; i < prev.size(); i++) nxt.push_back(prev[i]+prev[i-1]);
        nxt.push_back(1);
        return nxt;
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> v = {1};
        while (rowIndex > 0) {
            v = getNext(v);
            rowIndex--;
        }
        return v;
    }
};