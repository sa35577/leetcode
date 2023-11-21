class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<long long> N;
        for (int i : nums) {
            N.push_back((long long)(i));
        }
        int maxFrequency = 1;
        int score = 0, L = 0, R = 1;
        long long prev = N[0];
        while (R < nums.size()) {
            long long inc = ((long long)(R-1) - L + 1) * (N[R] - prev);
            while (L != R && score + inc > k) {
                inc -= N[R] - prev;
                score -= prev - N[L];
                L++;
            }
            score = score + inc;
            while (R+1 < N.size() && N[R+1] == N[R]) R++;
            // cout << L << " " << R << ": " << score << endl;
            maxFrequency = max(maxFrequency,R-L+1);
            prev = N[R];
            R++;
        }
        return maxFrequency;
    }
};