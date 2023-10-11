class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // want the maximal profit that is within the capital limit
        int curCapital = w;
        vector<pair<int,int>> capitalrank;
        priority_queue<int,vector<int>> pq; //pq <profit, index>

        for (int i = 0; i < capital.size(); i++) {
            capitalrank.push_back({capital[i],profits[i]});
            // profitrank.push_back({profits[i],{capital[i],i}});
        }
        sort(capitalrank.begin(),capitalrank.end());
        for (pair<int,int> p : capitalrank) cout << p.first << " " << p.second << endl;
        int idx = 0;
        while (idx < capitalrank.size() && capitalrank[idx].first <= curCapital) {
            pq.push(capitalrank[idx].second);
            idx++;
        }
        // cout << curCapital << endl;

        for (int rep = 0; rep < k; rep++) {
            if (pq.empty()) break;
            int val = pq.top();
            pq.pop();
            curCapital += val;
            // cout << curCapital << endl;
            while (idx < capitalrank.size() && capitalrank[idx].first <= curCapital) {
                pq.push(capitalrank[idx].second);
                idx++;
            }
            // cout << idx << endl;
        }
        
        return curCapital;
    }
};