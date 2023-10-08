class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<pair<long long,int>> pq;
        long long arr[100005];
        long long totSum = 0;
        for (int i = 0; i < nums1.size(); i++) {
            arr[i] = (long long)(abs(nums1[i]-nums2[i]));
            pq.push({arr[i],i});
            totSum += arr[i];
        }
        if (totSum <= (long long)(k1 + k2)) return 0LL;

        long long soFar = 0, rem = (long long)(k1 + k2);
        vector<int> indexesSeen;
        while (rem != 0) {
            pair<long long,int> p = pq.top();
            // cout << p.first << endl ;
            pq.pop();
            soFar++;
            indexesSeen.push_back(p.second);
            long long nxtDiff = 0;
            if (!pq.empty()) nxtDiff = pq.top().first;
            if (soFar * (p.first - nxtDiff) < rem) {
                rem -= soFar * (p.first - nxtDiff);

            }
            else {
                for (int x : indexesSeen) arr[x] = p.first; //collapse down first
                for (int x : indexesSeen) arr[x] -= rem / soFar;
                for (int i = 0; i < rem % soFar; i++) {
                    int x = indexesSeen[i];
                    arr[x]--;
                }
                rem = 0;
                break;
            }
        }
        long long res = 0;
        for (int i = 0; i < nums1.size(); i++) {
            res += arr[i] * arr[i];
        }
        return res;
    }
};