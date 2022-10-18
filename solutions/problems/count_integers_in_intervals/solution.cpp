class CountIntervals {
public:
    int cnt = 0;
    set<int> lefts;
    set<int> rights;
    map<int,int> pairs;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        if (pairs.empty()) {
            cnt = right-left+1;
            lefts.insert(left);
            rights.insert(right);
            pairs[left] = right;
            pairs[right] = left;
            return;
        }
        int curLeft = left, curRight = right;
        //if (left == 5 && right == 8) cout << cnt << " ";
        // match left intersections: check iterator from rights.lower_bound(left) <= right
        auto it = rights.lower_bound(left);
        while (it != rights.end()) {
            int rightEnd = *it;
            if (rightEnd <= right) {
                curLeft = min(curLeft,pairs[rightEnd]);
                curRight = max(curRight,rightEnd);
                lefts.erase(pairs[rightEnd]);
                rights.erase(rightEnd);
                cnt -= (rightEnd-pairs[rightEnd]+1);
                pairs.erase(pairs[rightEnd]);
                pairs.erase(rightEnd);
                it = rights.lower_bound(left);
            }
            else if (pairs[rightEnd] <= left) {
                curLeft = pairs[rightEnd];
                curRight = rightEnd;
                lefts.erase(pairs[rightEnd]);
                rights.erase(rightEnd);
                cnt -= (rightEnd-pairs[rightEnd]+1);
                pairs.erase(pairs[rightEnd]);
                pairs.erase(rightEnd);
                break;
            }
            else break;
        }
        //if (left == 5 && right == 8) cout << cnt << " ";
        // match right intersections: check iterator from lefts.lower_bound(left) <= right
        auto it2 = lefts.lower_bound(curLeft);
        while (it2 != lefts.end()) {
            int leftEnd = *it2;
            if (leftEnd <= right) {
                curRight = max(pairs[leftEnd],curRight);
                curLeft = min(leftEnd,curLeft);
                lefts.erase(leftEnd);
                rights.erase(pairs[leftEnd]);
                cnt -= (pairs[leftEnd]-leftEnd+1);
                pairs.erase(pairs[leftEnd]);
                pairs.erase(leftEnd);
                it2 = lefts.lower_bound(curLeft);
            }
            else break;
        }
        //if (left == 5 && right == 8) cout << cnt << " ";
        cnt += (curRight-curLeft+1);
        //if (left == 5 && right == 8) cout << cnt << " ";
        lefts.insert(curLeft);
        rights.insert(curRight);
        pairs[curLeft] = curRight;
        pairs[curRight] = curLeft;
    }
    
    int count() {
        //cout << pairs.size() << "\n";
        return cnt;

    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */