/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
#include <map>
class Solution {
public:
    map<int,int> mp;
    
    int getVal(int idx, MountainArray &mountainArr) {
        if (mp.find(idx) != mp.end()) return mp[idx];
        return mp[idx] = mountainArr.get(idx);
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int sz = mountainArr.length();
        //find peak element
        int L = 0, R = sz-1;
        int peak = -1;
        while (L <= R) {
            int mid = (L+R)/2;
            if (mid == 0) L = mid+1;
            else if (mid == sz-1) R = mid-1;
            else {
                int amid = getVal(mid,mountainArr), amidMinus = getVal(mid-1,mountainArr), amidPlus = getVal(mid+1,mountainArr);
                if (amid > amidMinus && amid > amidPlus) {
                    peak = mid;
                    break;
                }
                else if (amid > amidMinus && amid < amidPlus) L = mid+1;
                else R = mid-1;
            }
        }  
        
        if (target > getVal(peak,mountainArr)) return -1;
        else if (target == getVal(peak,mountainArr)) return peak;
        
        //check left side
        L = 0, R = peak-1;
        while (L < R) {
            int mid = (L+R)/2;
            if (getVal(mid,mountainArr) > target) R = mid-1;
            else if (getVal(mid,mountainArr) == target) R = mid;
            else L = mid+1;
            
	    }
        if (target == getVal(L,mountainArr)) return L;
        
        //check right side
        L = peak+1, R = sz-1;
        while (L < R) {
            int mid = (L+R)/2;
            if (getVal(mid,mountainArr) < target) R = mid-1;
            else if (getVal(mid,mountainArr) == target) R = mid;
            else L = mid+1;
            
	    }
        if (target == getVal(L,mountainArr)) return L;
        else if (target == getVal(R,mountainArr)) return R;
        //not there
        
        return -1;

        
    }
};