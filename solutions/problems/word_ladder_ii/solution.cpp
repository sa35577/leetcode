class Solution {
public:
    bool oneDiff(string &a, string &b) {
        int L = 0, R = (int)(b.size())-1;
        while (L < a.size() && a[L] == b[L]) L++;
        while (R >= 0 && a[R] == b[R]) R--;
        return (L == R);
    }
    vector<vector<int>> graph;
    int start = 0, finish = 0;
    vector<int> minDist;

    vector<vector<string>> backTrack(int node, int curDist, vector<string>& wlist) {
        vector<vector<string>> res;
        if (node == start) return {{wlist[start]}};
        for (int prev : graph[node]) {
            if (minDist[prev] == curDist-1) {
                vector<vector<string>> prevres = backTrack(prev,curDist-1,wlist);
                for (vector<string> &v : prevres) v.push_back(wlist[node]);
                res.insert(res.end(),prevres.begin(),prevres.end());
            }
        }
        return res;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        if (find(wordList.begin(),wordList.end(),beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }
        if (find(wordList.begin(),wordList.end(),endWord) == wordList.end()) {
            return {};
        }
        graph.resize(wordList.size());
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) start = i;
            else if (wordList[i] == endWord) finish = i;
            for (int j = i+1; j < wordList.size(); j++) {
                // cout << i << " " << j << endl;
                if (oneDiff(wordList[i],wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        //bfs
        queue<pair<int,int>> q;
        q.push({start,0});
        minDist.resize(wordList.size());
        
        fill(minDist.begin(),minDist.end(),INT_MAX);
        minDist[start] = 0;
        
        cout << "here\n";
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            int node = cur.first, dist = cur.second;
            q.pop();
            for (int nxt : graph[node]) {
                if (minDist[nxt] > minDist[node] + 1) {
                    minDist[nxt] = minDist[node] + 1;
                    q.push({nxt,minDist[nxt]});
                }
            }
        }
        cout << "here\n";

        //backtrack
        if (minDist[finish] == INT_MAX) return {};
        return backTrack(finish,minDist[finish],wordList);
    }
};