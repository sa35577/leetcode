class Solution {
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> dp[31],ndp[31];
        vector<int> e;
        dp[0].push_back(e);
        ndp[0].push_back(e);
        for (int c = 0; c < candidates.size(); c++) {
            int originalCandidate = candidates[c];
            int freq = 1;
            while (c+1 < candidates.size() && candidates[c+1] == candidates[c]) {
                freq++;
                c++;
            }
            vector<int> v;
            for (int i = 0; i < freq; i++) v.push_back(originalCandidate);
            for (int x = freq; x >= 1; x--) {
                int candidate = originalCandidate * x;
                for (int i = target; i >= candidate; i--) {
                    for (vector<int> w : dp[i - candidate]) {
                        ndp[i].push_back(w);
                        ndp[i].back().insert(ndp[i].back().end(),v.begin(),v.end());
                    }
                }
                v.pop_back();
            }
            for (int i = 0; i <= target; i++) dp[i] = ndp[i];
            
        }
        sort(dp[target].begin(),dp[target].end());
        return dp[target];


    }

    // struct Pos {
    //     vector<Pos> v;
    //     int val = 0;
    //     bool canZero = false;
    // } dp[105][35];

    // vector<vector<int>> recRes(Pos p) {
    //     //cout << p.v.size() << " " << p.val << "asdfasdf\n";
    //     vector<vector<int>> res;
    //     if (p.canZero) {
    //         vector<int> vv;
    //         res.push_back(vv);
    //         return res;
    //     }


    //     for (Pos nxt : p.v) {
    //         vector<vector<int>> rec = recRes(nxt);
    //         for (vector<int> blah : rec) {
    //             blah.push_back(p.val);
    //             res.push_back(blah);
    //         }
    //     }

    //     return res;
    // }

    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     sort(candidates.begin(),candidates.end());
    //     for (int i : candidates) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    //     //reverse(candidates.begin(),candidates.end());
    //     vector<Pos> vw;
    //     for (int i = 0; i < 105; i++) {
    //         for (int j = 0; j < 35; j++) {
    //             dp[i][j].v = vw;
    //             dp[i][j].val = 0;
    //             if (j == 0) dp[i][j].canZero = true;
    //         }
    //     }

    //     vector<vector<int>> res;

    //     for (int i = 1; i <= candidates.size(); i++) {

    //         for (int j = 1; j <= target; j++) {
    //             dp[i][j].v.insert(dp[i][j].v.end(),dp[i-1][j].v.begin(),dp[i-1][j].v.end());
    //             if (j - candidates[i-1] == 0 || (j - candidates[i-1] >= 0 && dp[i-1][j - candidates[i-1]].val > 0)) {
    //                 //cout << i << " " << j << endl;
    //                 dp[i][j].v.push_back(dp[i-1][j - candidates[i-1]]);
    //                 dp[i][j].val = candidates[i-1];
    //             }
    //             cout << dp[i][j].v.size() << " ";
    //         }
    //         cout << endl;
            
    //         // vector<vector<int>> candidateTotalSoFar = recRes(dp[i][target]);
    //         // res.insert(res.end(),candidateTotalSoFar.begin(),candidateTotalSoFar.end());
    //     }

    //     return recRes(dp[candidates.size()][target]);





    // }

    // // vector<vector<int>> csum(deque<int>& candidates, int target) {
    // //     vector<vector<int>> res;
    // //     if (candidates.empty() || target < 0) {
    // //         if (target == 0) {
    // //             res.push_back({});
    // //         }
    // //         return res;
    // //     }
    // //     int x = candidates.front();
    // //     candidates.pop_front();
    // //     vector<vector<int>> rec1 = csum(candidates,target);
    // //     vector<vector<int>> rec2 = csum(candidates,target-x);
    // //     for (int i = 0; i < rec2.size(); i++) {
    // //         rec2[i].push_back(x);
    // //     }
    // //     candidates.push_front(x);
    // //     res.insert(res.end(),rec1.begin(),rec1.end());
    // //     res.insert(res.end(),rec2.begin(),rec2.end());
    // //     return res;

    // // }
    // // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // //     deque<int> stck;
    // //     for (int i : candidates) {
    // //         int x = i;
    // //         if (x <= target)
    // //             stck.push_back(i);
    // //     }
    // //     vector<vector<int>> v = csum(stck,target);
    // //     set<vector<int>> s;
    // //     for (int i = 0; i < v.size(); i++) {
    // //         sort(v[i].begin(),v[i].end());
    // //         s.insert(v[i]);
    // //     }
    // //     v.clear();
    // //     for (auto it = s.begin(); it != s.end(); it++) {
    // //         v.push_back(*it);
    // //     }
    // //     // vector<vector<int>> v = csum(stck,target);
    // //     // for (int i = 0; i < v.size(); i++) {
    // //     //     sort(v[i].begin(),v[i].end());
    // //     // }
    // //     // sort(v.begin(),v.end());
    // //     return v;
    // // }
};