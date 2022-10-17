class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    //left: -1 or 9 mod 10, right: 1 mod 10
    void addNum(int value) {
        auto it = s.lower_bound(10*value);
        if (s.empty()) {
            s.insert(10*value-1);
            s.insert(10*value+1);
            return;
        }
        if (it == s.end()) {
            //check if next to last endpoint
            auto it2 = s.rbegin();
            int lastEnd = *it2;
            if (lastEnd == 10*(value-1) + 1) {
                s.erase(lastEnd);
                s.insert(lastEnd+10);
                return;
            }
            s.insert(10*value-1);
            s.insert(10*value+1);
            return;
        }
        int x = *it;
        if (x > 0 && x % 10 == 1) { //inside of a current interval
            return;
        }
        //otherwise, check if next to the previous end point and next to new start point
        bool mergeLeft = false, mergeRight = false;
        auto it2 = s.lower_bound(10*(value-1));
        int lastEnd = *it2;
        if (lastEnd == 10 * (value-1) + 1) {
            mergeLeft = true;
        }
        if (x == 10*(value+1)-1) {
            mergeRight = true;
        }

        if (mergeLeft && mergeRight) {
            s.erase(10*(value-1)+1);
            s.erase(10*(value+1)-1);
        }
        else if (mergeLeft) {
            s.erase(10*(value-1)+1);
            s.insert(10*value+1);
        }
        else if (mergeRight) {
            s.erase(10*(value+1)-1);
            s.insert(10*value-1);
        }
        else {
            s.insert(10*value-1);
            s.insert(10*value+1);
        }



    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        auto it = s.begin();
        while (it != s.end()) {
            vector<int> v;
            int x1 = *it;
            v.push_back((x1+1)/10);
            it++;
            int x2 = *it;
            v.push_back((x2-1)/10);
            it++;
            ret.push_back(v);
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */