class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size()-1;
        int maxArea = min(height[0],height.back()) * (R-L);
        while (L < R) {
            if (height[L] <= height[R]) {
                L++;
            }
            else R--;
            maxArea = max(maxArea,min(height[L],height[R]) * (R-L));
        }
        return maxArea;
    }
};