#include <set>
#include <algorithm>
#include <map>
class MyCalendarThree {
public:
    multiset<long long> s;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        long long ss = start, ee = end;
        s.insert(ss*10 + 1);
        s.insert(ee*10 - 1);
        int cnt = 0, mx = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            long long cur = *it;
            //cout << cur << " ";
            if (cur == -1 || cur % 10 == 9) {
                cnt--;
            }
            else {
                cnt++;
            }
            mx = max(mx,cnt);
        }
        //cout << endl;
        return mx;

    }
    // set<pair<int,int>> s; // L,R
    // set<pair<int,int>> srev; // R,L
    // map<pair<int,int>,int> cons;
    // int mx = 0;
    // MyCalendarThree() {
        
    // }
    
    // int book(int start, int end) {
    //     if (s.empty()) {
    //         s.insert(make_pair(start,end));
    //         srev.insert(make_pair(end,start));
    //         mx = 1;
    //         cons[make_pair(start,end)] = 1;
    //         return mx;
    //     }
    //     //right end combintation : [L1, R1) has that the next lefts < R1
    //     int newEnd = end;
    //     auto it = s.lower_bound(make_pair(start,-1));
    //     int cnt = 1;
    //     while (it != s.end()) {
    //         pair<int,int> p = *it;
    //         if (p.first >= end) break;
    //         s.erase(p);
    //         srev.erase(make_pair(p.second,p.first));
    //         cnt += cons[p];
    //         cons.erase(p);
    //         newEnd = max(newEnd,p.second);
    //         it = s.lower_bound(make_pair(start,-1));
    //     }
    //     cout << cnt << " ";
    //     //left end combintation: [L1,R1) has the previous rights > L1

    //     auto it2 = srev.lower_bound(make_pair(start,-1));
    //     int newBeginning = start;
    //     while (it2 != srev.end()) {
    //         pair<int,int> p = *it2;
    //         if (p.second >= end) break;
    //         s.erase(make_pair(p.second,p.first));
    //         srev.erase(p);
    //         cnt += cons[make_pair(p.second,p.first)];
    //         cons.erase(make_pair(p.second,p.first));
    //         newBeginning = min(newBeginning,p.second);
    //         it2 = srev.lower_bound(make_pair(start,-1));
    //     }
    //     cout << cnt << endl;
    //     s.insert(make_pair(newBeginning,newEnd));
    //     srev.insert(make_pair(newEnd,newBeginning));
    //     cons[make_pair(newBeginning,newEnd)] = cnt;
    //     mx = max(mx,cnt);
    //     return mx;
    // }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */