class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bool seenA[55],seenB[55];
        memset(seenA,0,sizeof(seenA));
        memset(seenB,0,sizeof(seenB));
        int cnt = 0;
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            if (seenB[A[i]]) cnt++;
            if (seenA[B[i]]) cnt++;
            if (A[i] == B[i]) cnt++;
            seenB[B[i]] = 1;
            seenA[A[i]] = 1;
            res.push_back(cnt);

        }
        return res;

    }
};