class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = minutes * 6;
        double h = hour * 30;
        if (h >= 360) h -= 360;
        h += (minutes / 60.0) * 30;
        if (m >= h) swap(m,h);
        //m is smaller than h
        return min(h-m,m-h+360);
        
    }
};