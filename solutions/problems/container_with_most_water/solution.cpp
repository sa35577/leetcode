class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0, L = 0, R = height.size()-1;
        while (L < R) {
            mx = max(min(height[L],height[R])*(R-L),mx);
            if (height[L] > height[R]) R--;
            else L++;
        }
        return mx;
    }
};