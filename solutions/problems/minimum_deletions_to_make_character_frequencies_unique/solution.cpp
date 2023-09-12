class Solution {
public:
    int minDeletions(string s) {
        int freq[26];
        for (int i = 0; i < 26; i++) freq[i] = 0;
        for (char c : s) {
            freq[c-'a']++;
        }
        map<int,int> mp;
        for (int i = 0; i < 26; i++) {
            if (mp.find(freq[i]) == mp.end()) mp[freq[i]] = 1;
            else mp[freq[i]]++;
        }
        for (int i = 0; i < 26; i++) {
            //cout << i << " " << freq[i] << endl;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(make_pair(it->first,it->second));
        }
        int cost = 0;
        while (!pq.empty()) {
            pair<int,int> p = pq.top();
            if (p.first == 0) break;
            //cout << p.first << " " << p.second << endl;
            pq.pop();
            if (pq.empty()) {
                //base case
                int needtoshift = p.second-1;
                cost += (needtoshift * (needtoshift+1))/2;
            }
            else {
                int nxt = pq.top().first;
                if (p.second <= p.first-nxt) {
                    //base case
                    int needtoshift = p.second-1;
                    cost += (needtoshift * (needtoshift+1))/2;
                }
                else {
                    //put onto next
                    int needtoshift = p.first-nxt-1;
                    cost += (needtoshift * (needtoshift+1))/2;
                    cost += (p.second - needtoshift - 1) * (p.first-nxt);  
                    pair<int,int> q = pq.top();
                    pq.pop();
                    q.second += p.second - needtoshift - 1;
                    pq.push(q);
                }
            }
            //cout << cost << endl;
        }
        return cost;
    }
};