class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto itright = s.lower_bound(make_pair(end,-1));
        if (itright == s.begin()) {
            s.insert(make_pair(start,end));
            return true;
        }
        auto itleft = std::prev(itright);
        pair<int,int> p = *itleft;
        if (p.second <= start) {
            s.insert(make_pair(start,end));
            return true;
        }
        return false;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */