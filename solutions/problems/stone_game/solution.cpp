class Solution {
public:
    // map<pair<int,int>,pair<int,int>> mp; //pair<start,end> -> pair<alice,bob>
    // pair<int,int> game(vector<int>& piles, int L, int R) {
    //     if (mp.find({L,R}) != mp.end()) return mp[{L,R}];
    //     if (L == R) {
    //         mp[{L,R}] = {0,piles[L]};
    //         return mp[{L,R}];
    //     }
    //     pair<int,int> p1 = game(piles,L+1,R), p2 = game(piles,L,R-1);
    //     pair<int,int> res = {-1,-1};
    //     if ((R-L) % 2 == 1) {
    //         //alice
    //         if (piles[L] + p1.first - p1.second >= piles[R] + p2.first - p2.second) {
    //             res = {piles[L] + p1.first, p1.second};
    //         }
    //         else res = {piles[R] + p2.first, p2.second};
    //     }
    //     else {
    //         //bob
    //         if (piles[L] + p1.second - p1.first >= piles[R] + p2.second - p2.first) {
    //             res = {p1.first, piles[L] + p1.second};
    //         }
    //         else res = {p2.first, piles[R] + p2.second};
    //     }
    //     mp[{L,R}] = res;
    //     return res;
    // }
    // bool stoneGame(vector<int>& piles) {
    //     pair<int,int> p =  game(piles,0,piles.size()-1);
    //     return (p.first > p.second);
    // }
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};