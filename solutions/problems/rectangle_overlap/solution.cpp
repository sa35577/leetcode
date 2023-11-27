class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1 = rec1[0], ay1 = rec1[1], ax2 = rec1[2], ay2 = rec1[3];
        int bx1 = rec2[0], by1 = rec2[1], bx2 = rec2[2], by2 = rec2[3];

        return !(ax2 <= bx1 || bx2 <= ax1 || ay2 <= by1 || by2 <= ay1);
    }
};