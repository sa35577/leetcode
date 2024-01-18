class Solution {
public:
    int maxJump(vector<int>& stones) {
        if (stones.size() == 2) return stones.back();
        int mx = -1;
        if (stones.size() % 2 == 1) {
            //last index is even
            //0 -> 2 -> 4 -> ... -> N
            //0 -> 1 -> 3 -> ... -> N-1 -> N
            for (int i = 2; i < stones.size(); i+= 2) {
                mx = max(mx,stones[i] - stones[i-2]);
            }
            mx = max(mx,stones[1] - stones[0]);
            mx = max(mx,stones[stones.size()-1] - stones[stones.size()-2]);
            for (int i = 3; i < stones.size(); i+= 2) {
                mx = max(mx,stones[i] - stones[i-2]);
            }
            return mx;
        }
        else {
            // 0 -> 2 -> 4 -> .... -> N-1 -> N
            // 0 -> 1 -> 3 -> .... -> N
            mx = max(mx,stones[1] - stones[0]);
            mx = max(mx,stones[stones.size()-1] - stones[stones.size()-2]);
            for (int i = 2; i < stones.size(); i+= 2) mx = max(mx,stones[i] - stones[i-2]);
            for (int i = 3; i < stones.size(); i += 2) mx = max(mx,stones[i] - stones[i-2]);
            return mx;
        }
        // int L = 1, R = stones.back();
        // while (L+1 < R) {
        //     int mid = (L+R)/2;
        //     if (test(stones,mid)) R = mid;
        //     else L = mid+1;
        // }
        // if (test(stones,L)) return L;
        // return R;
    }
};