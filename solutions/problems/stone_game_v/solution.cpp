class Solution {
public:
    // unordered_map<pair<int,int>,int> mp; //<left,right> -> score
    int mp[501][501];
    bool vis[501][501];
    int game(vector<int> &vals, vector<int>& psa, int L, int R) {
        if (vis[L][R]) return mp[L][R];
        if (L == R) {
            vis[L][R] = true;
            mp[L][R] = 0;
            return mp[L][R];
        }
        int mx = -1;
        for (int i = L; i < R; i++) {
            //divide into [L,i] and [i+1,R]
            int lsum = 0;
            if (L == 0) lsum = psa[i] - 0;
            else lsum = psa[i] - psa[L-1];
            int rsum = 0;
            rsum = psa[R] - psa[i];
            // if (L == 3 && R == 5) {
            //     cout << i << " " << lsum << " " << rsum << endl;
            // }
            if (lsum > rsum) {
                mx = max(mx,game(vals,psa,i+1,R) + rsum);
                // cout << "1: " << game(vals,psa,i+1,R) + rsum << endl;
            }
            else if (lsum < rsum) {
                mx = max(mx,game(vals,psa,L,i) + lsum);
                // cout << "2: " << game(vals,psa,L,i) + lsum << endl;
            }
            else {
                mx = max(mx,lsum + max(game(vals,psa,L,i),game(vals,psa,i+1,R)));
                // cout << "3: " << lsum + max(game(vals,psa,L,i),game(vals,psa,i+1,R)) << endl;
            }
        }
        mp[L][R] = mx;
        vis[L][R] = true;
        // cout << L << " " << R << " " << mx << endl;
        return mx;
    }
    int stoneGameV(vector<int>& stoneValue) {
        vector<int> psa{stoneValue[0]};
        for (int i = 1; i < stoneValue.size(); i++) psa.push_back(psa.back() + stoneValue[i]);
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        for (int sz = 1; sz < stoneValue.size()+1; sz++) {
            for (int i = 0; i + sz - 1 < stoneValue.size(); i++) {
                game(stoneValue,psa,i,i + sz - 1);
            }
        }
        return game(stoneValue,psa,0,stoneValue.size()-1);
    }
};