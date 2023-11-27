class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int comb = abs(ax1 - ax2) * abs(ay1 - ay2) + abs(bx1 - bx2) * abs(by1 - by2);
        if (ay1 >= by2 || by1 >= ay2 || ax1 >= bx2 || bx1 >= ax2) {
            return comb;
        }
        int h = min(ay2,by2) - max(ay1,by1);
        int w = min(ax2,bx2) - max(ax1,bx1);
        return comb - h * w;
    }
};