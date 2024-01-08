class Solution {
public:
    int bsearch(vector<int>& heaters, int house) {
        int L = 0, R = heaters.size()-1;
        if (heaters.back() < house) return heaters.size(); 
        // lower bound search
        while (L < R) {
            int mid = (L+R)/2;
            if (heaters[mid] == house) return mid;
            else if (heaters[mid] > house) {
                if (mid-1 >= L && heaters[mid-1] >= house) {
                    R = mid-1;
                }
                else return mid;
            }
            else if (heaters[mid] < house) {
                L = mid+1;
            }
        }
        return L;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int mx = -1;
        for (int house : houses) {
            int idx = bsearch(heaters,house);
            if (idx == heaters.size()) {
                idx--;
                mx = max(mx,abs(heaters[idx] - house));
            }
            else if (idx == 0) {
                mx = max(mx,abs(heaters[idx] - house));
            }
            else {
                int idx2 = idx;
                idx2--;
                mx = max(mx,min(heaters[idx] - house, house - heaters[idx2]));
            }
        }
        return mx;
    }
};