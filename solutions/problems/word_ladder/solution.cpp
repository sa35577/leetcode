#define ll long long
class Solution {
public:
    vector<ll> power;
    
    ll hashString(string word) {
        ll curHash = 0;
        for (int i = 0; i < word.size(); i++) {
            curHash += (ll)(word[i]-'a') * power[i];
        }
        return curHash;
    }

    bool oneDiff(string a, string b) {
        int L = 0, R = a.size()-1;
        while (L < a.size() && a[L] == b[L]) L++;
        while (R >= 0 && a[R] == b[R]) R--;
        return (L == R);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        power.resize(11);
        power[0] = 1;
        for (int i = 1; i <= 10; i++) power[i] = (ll)(26) * power[i-1];
        set<string> st;
        for (string word : wordList) {
            st.insert(word);
        }
        st.insert(beginWord);
        wordList.clear();
        for (auto it = st.begin(); it != st.end(); it++) {
            wordList.push_back(*it);
        }

        vector<ll> hash;
        for (string word : wordList) {
            hash.push_back(hashString(word));
        } 
        // cout << beginWord << " " << hashString(beginWord) << endl;
        // cout << endWord << " " << hashString(endWord) << endl;
        unordered_map<ll,vector<ll>> graph;
        for (int i = 0; i < hash.size(); i++) {
            for (int j = 0; j < i; j++) {
                ll diff = hash[i] - hash[j];
                if (diff < 0) diff = -diff;
                for (int k = 0; k < 10; k++) {
                    if (diff % power[k] == 0 && diff / power[k] < 26 && oneDiff(wordList[i],wordList[j])) {
                        //cout << i << " " << j << endl;
                        if (graph.find(hash[i]) == graph.end()) {
                            vector<ll> v{hash[j]};
                            graph[hash[i]] = v;
                        }
                        else graph[hash[i]].push_back(hash[j]);

                        if (graph.find(hash[j]) == graph.end()) {
                            vector<ll> v{hash[i]};
                            graph[hash[j]] = v;
                        }
                        else graph[hash[j]].push_back(hash[i]);
                        break;
                    }
                }
            }
        }
        if (graph.find(hashString(endWord)) == graph.end()) return 0;

        map<ll,int> vis;
        for (auto it = graph.begin(); it != graph.end(); it++) {
            ll key = it->first;
            vis[key] = INT_MAX;
        }
        vis[hashString(beginWord)] = 0;
        
        priority_queue<pair<int,ll>,vector<pair<int,ll>>,greater<pair<int,ll>>> pq;
        pq.push({0,hashString(beginWord)});

        while (!pq.empty()) {
            pair<int,ll> cur = pq.top();
            int dist = cur.first, idx = cur.second;
            // if (dist <= 1) {
            //     cout << dist << " " << idx << endl;
            // }
            pq.pop();
            if (vis[idx] < dist) continue;
            
            for (ll nxt : graph[idx]) {
                if (vis[nxt] >= dist+1) {
                    pq.push({dist+1,nxt});
                    vis[nxt] = dist+1;
                }
            }
        }
        //cout << vis[hashString(endWord)] << endl;
        if (vis[hashString(endWord)] == INT_MAX) return 0;
        return vis[hashString(endWord)] + 1;
        

    }
};