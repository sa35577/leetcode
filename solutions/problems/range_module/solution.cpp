class RangeModule {
public:
    set<pair<int,int>> lr;
    set<pair<int,int>> rl;
    RangeModule() {
        //strategy, always do [left, right-1]
    }
    
    void addRange(int left, int right) {
        right--;
        //check to see if the range is already included in an interval
        auto includedIterator = rl.upper_bound({right,-1});
        if (includedIterator != rl.end() && includedIterator->second <= left) {
            return;
        }
        //if not, then get all intervals touching, update left and right ends accordingly, and remove touching intervals and add this new one
        //intervals touching either have their left end in the new interval range or the right end in the new interval range
        set<pair<int,int>> deletes;
        for (auto it = lr.lower_bound({left,-1}); it != lr.end() && it->first <= right+1; it++) {
            deletes.insert(*it);
            left = min(left,it->first);
            right = max(right,it->second);
        }
        for (auto it = rl.lower_bound({left-1,-1}); it != rl.end() && it->first <= right; it++) {
            pair<int,int> p = *it;
            swap(p.first,p.second);
            deletes.insert(p);
            left = min(left,p.first);
            right = max(right,p.second);
        }
        for (pair<int,int> p : deletes) {
            lr.erase(p);
            pair<int,int> q;
            q.first = p.second;
            q.second = p.first;
            rl.erase(q);
        }
        lr.insert({left,right});
        rl.insert({right,left});
        // for (pair<int,int> p : lr) {
        //     cout << p.first << " " << p.second << ", ";
        // }
        // cout << endl;

    }
    
    bool queryRange(int left, int right) {
        right--;
        if (lr.empty()) return false;
        auto includedIterator = rl.upper_bound({right,-1});
        if (includedIterator != rl.end() && includedIterator->second <= left) {
            return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        right--;
        set<pair<int,int>> deletes;
        set<pair<int,int>> recovers;
        for (auto it = lr.begin(); it != lr.end(); it++) {
            pair<int,int> p = *it;
            if (p.first < left) {
                if (p.second < left) ;
                else if (p.second <= right) {
                    deletes.insert(p);
                    recovers.insert({p.first,left-1});
                }
                else if (p.second > right) {
                    deletes.insert(p);
                    recovers.insert({p.first,left-1});
                    recovers.insert({right+1,p.second});
                }
            }
            else if (p.first >= left && p.first <= right) {
                deletes.insert(p);
                if (p.second <= right) {
                    ;
                }
                else if (p.second > right) {
                    recovers.insert({right+1,p.second});
                }
            }
            // if (p.first <= left) {
            //     if (p.second < left) return;
            //     if (p.second >= left && p.second <= right) {
            //         deletes.insert(p);
            //         if (p.second == right) {
            //             ;
            //         }
            //         else {
            //             recovers.insert({p.second+1,right});
            //         }
            //     }
            //     else if (p.second > right) {
            //         deletes.insert(p);
            //         recovers.insert({right,p.second});
                    
            //     }
            // }
            // else {
            //     //p.first > left
            //     deletes.insert(p);
            //     recovers.insert({left,p.first-1});
            //     if (p.second > right) {
            //         recovers.insert(right+1,p.second});
            //     }
            // }
        }
        for (pair<int,int> p : deletes) {
            lr.erase(p);
            pair<int,int> q;
            q.first = p.second;
            q.second = p.first;
            rl.erase(q);
        }
        for (pair<int,int> p : recovers) {
            lr.insert(p);
            pair<int,int> q;
            q.first = p.second;
            q.second = p.first;
            rl.insert(q);
        }
        // for (pair<int,int> p : lr) {
        //     cout << p.first << " " << p.second << ", ";
        // }
        // cout << endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */