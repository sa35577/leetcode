#include <bits/stdc++.h>
class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq; //distance, node
        
        vector<int> vis(arr.size());
        for (int i = 0; i < vis.size(); i++) vis[i] = INT_MAX;
        vis[0] = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i]) == mp.end()) {
                vector<int> nv = {i};
                mp[arr[i]] = nv;
            }
            else mp[arr[i]].push_back(i);
        }
        
        pq.push({0,0});
        
        while (!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            
            if (vis[cur.second] == cur.first) {
                if (cur.second-1 >= 0 && vis[cur.second-1] > 1+cur.first) {
                    vis[cur.second-1] = 1+cur.first;
                    pq.push({1+cur.first,cur.second-1});
                }
                if (cur.second+1 < vis.size() && vis[cur.second+1] > 1+cur.first) {
                    vis[cur.second+1] = 1+cur.first;
                    pq.push({1+cur.first,cur.second+1});
                }
                for (int nxt : mp[arr[cur.second]]) {
                    if (vis[nxt] > 1+cur.first) {
                        vis[nxt] = 1+cur.first;
                        pq.push({1+cur.first,nxt});
                    }
                }
                mp[arr[cur.second]].clear();
                if (vis[vis.size()-1] <= cur.first) break;
                
            }
            
            
        }
        return vis[vis.size()-1];
        
        
        
    }
};