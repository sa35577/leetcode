class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return (int)(tasks.size());
        int rem[26];
        memset(rem,0,sizeof(rem));
        for (char task : tasks) {
            rem[task-'A']++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        int wait[26];
        memset(wait,0,sizeof(wait));
        for (int i = 0; i < 26; i++) {
            if (rem[i] > 0) {
                pq.push({rem[i],i});
            }
        }
        int sim = 0;
        int totwait = 0;
        while (totwait > 0 || pq.size() > 0) {
            if (pq.size() > 0) {
                pair<int,int> cur = pq.top();
                pq.pop();
                rem[cur.second]--;
                if (n > 0 && rem[cur.second] > 0) wait[cur.second] = n;
                sim++;
                for (int i = 0; i < 26; i++) {
                    if (i != cur.second) {
                        if (wait[i] == 1) {
                            pq.push({rem[i],i});
                            wait[i] = 0;
                        }
                        else if (wait[i] != 0) wait[i]--;
                    }
                }
            }
            else {
                int minwait = INT_MAX;
                for (int i = 0; i < 26; i++) {
                    if (wait[i] > 0) minwait = min(minwait,wait[i]);
                }
                sim += minwait;
                for (int i = 0; i < 26; i++) {
                    if (wait[i] == minwait) {
                        pq.push({rem[i],i});
                    }
                    if (wait[i] > 0) wait[i] -= minwait;
                }
            }
            
            totwait = 0;
            for (int i = 0; i < 26; i++) {
                if (wait[i] > 0) totwait++;
            }
        }
        return sim;
    }
};