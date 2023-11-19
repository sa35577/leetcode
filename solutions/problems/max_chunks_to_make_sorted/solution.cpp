class Solution {
public:
    vector<bool> seen;
    bool seenAll(int L, int R) {
        bool res = true;
        for (int i = L; i <= R; i++) res = (res && seen[i]);
        return res;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int numChunks = 0;
        int L = 0;
        int R = 0;
        
        for (int i : arr) seen.push_back(false);
        while (L < arr.size()) {
            numChunks++;
            R = L;
            seen[arr[L]] = true;
            while (R < arr.size() && !seenAll(L,R)) {
                R++; 
                if (R < arr.size()) seen[arr[R]] = true;
            }
            if (R == arr.size()) break;
            L = R+1;
        }
        return numChunks;
    }
};