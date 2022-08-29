class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int,vector<int>,greater<int>> pq;
        map<int,int> mp;
        for (int i = 0; i <= 100000; i++) pq.push(i);
        set<pair<int,pair<int,int>>> s;
        //set<time,pair<leave=0,arrive=1,id>>
        for (int i = 0; i < times.size(); i++) {
            s.insert({times[i][0],{1,i}});
            s.insert({times[i][1],{0,i}});
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            pair<int,pair<int,int>> cur = *it;
            if (cur.second.first == 1) {
                int idx = pq.top();
                if (targetFriend == cur.second.second) return idx;
                pq.pop();
                mp[cur.second.second] = idx;
            }
            else {
                pq.push(mp[cur.second.second]);
                
            }
            
            
        }
        return -1;
    }
};