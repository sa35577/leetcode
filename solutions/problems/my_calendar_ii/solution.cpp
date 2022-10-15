class MyCalendarTwo {
public:
    multiset<long long> s;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        long long ss = start, ee = end;
        long long L = ss*10 + 1, R = ee*10-1;
        int cnt = 0;
        bool bad = false;
        bool linsert = false, rinsert = false;
        for (auto it = s.begin(); it != s.end(); it++) {
            long long cur = *it;
            if (cur >= L && !linsert) {
                cnt++;
                linsert = true;
            }
            if (cnt >= 3) {
                bad = true;
                break;
            }
            if (cur >= R && !rinsert) {
                cnt--;
                rinsert = true;
            }
            if (cur % 10 == 1) {
                cnt++;
            }
            else {
                cnt--;
            }
            if (cnt >= 3) {
                bad = true;
                break;
            }
            //cout << cur << " ";
        }
        //cout << endl;
        if (!bad) {
            s.insert(L);
            s.insert(R);
        }
        return !bad;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */