class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, long long> freq;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i : nums) {
            if (freq.find(i) == freq.end()) {
                freq[i] = 1;
                pq.push(i);
            }
            else {
                freq[i]++;
                
            }
        }
        long long sum = 0;
        while (!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            if (pq.empty()) {
                //defer all now here
                long long defer = freq[cur] - 1;
                sum += (defer * (defer + 1)) / 2;
                break;
            }
            else {
                int nxt = pq.top();
                long long defer = freq[cur]-1;
                if (defer < nxt - cur) {
                    sum += (defer * (defer + 1)) / 2;
                }
                else {
                    long long canDefer = nxt - cur-1; //spots in between
                    sum += (canDefer * (canDefer + 1))/2;
                    long long rem = defer - canDefer;
                    sum += rem * (nxt - cur);
                    freq[nxt] += rem;
                }
            }
            //cout << sum << " ";
        }
        return (int)(sum);
        // map<int,long long> freq;
        // priority_queue<long long,vector<long long>,greater<long long>> pq;
        // for (int i : nums) {
        //     if (freq.find(i) == freq.end()) {
        //         freq[i] = 1;
        //     }
        //     else {
        //         freq[i]++;
        //         if (freq[i] == 2) pq.push(i);
        //     }
        // }
        // long long cost = 0;
        // while (!pq.empty()) {
        //     int x = pq.top();
        //     pq.pop();
        //     for (int i = 1; i <= freq[x]-1; i++) {
        //         if (freq.find(x+i) != freq.end()) {
        //             freq[x+i]++;
        //             if (freq[x+i] == 2) pq.push(x+i);
        //         }
        //         else {
        //             freq[x+i] = 1;
        //         }
        //     }
        //     cost += (freq[x]*(freq[x]-1))/2;
        //     freq[x] = 1;
        // }
        // return (int)(cost);
    }
};