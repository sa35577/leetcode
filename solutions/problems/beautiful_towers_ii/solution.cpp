class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<long long> scoreLeft(maxHeights.size()), scoreRight(maxHeights.size());
        // in the stack, between two indexes of entries L and R, all heights[L]...heights[R-1] are the same value
        stack<pair<long long, int>> heights;
        long long score = 0;
        for (int i = 0; i < maxHeights.size(); i++) {
            long long height = (long long)(maxHeights[i]);
            int prevIdx = i, R = i;
            while (!heights.empty() && heights.top().first >= height) {
                prevIdx = heights.top().second;
                long long oldHeight = heights.top().first;
                heights.pop();
                score -= (long long)((R-1) - prevIdx + 1) * oldHeight;
                R = prevIdx;
            }
            score += (long long)(i-R+1) * height;
            heights.push({height,R});
            scoreLeft[i] = score;
            // cout << score << endl;
            
        }
        // cout << "------" << endl;
        reverse(maxHeights.begin(),maxHeights.end());
        while (!heights.empty()) heights.pop();
        score = 0;
        for (int i = 0; i < maxHeights.size(); i++) {
            long long height = (long long)(maxHeights[i]);
            int prevIdx = i, R = i;
            while (!heights.empty() && heights.top().first >= height) {
                prevIdx = heights.top().second;
                long long oldHeight = heights.top().first;
                heights.pop();
                score -= (long long)((R-1) - prevIdx + 1) * oldHeight;
                R = prevIdx;
            }
            score += (long long)(i-R+1) * height;
            heights.push({height,R});
            scoreRight[i] = score;
            // cout << score << endl;
        }
        reverse(scoreRight.begin(),scoreRight.end());
        reverse(maxHeights.begin(),maxHeights.end());
        long long mx = -1;
        // // cout << "-----" << endl;
        // for (long long x : scoreLeft) cout << x << " ";
        // cout << endl;
        // for (long long x : scoreRight) cout << x << " ";
        cout << endl;
        for (int i = 0; i < maxHeights.size(); i++) {
            long long height = (long long)(maxHeights[i]);
            mx = max(mx,scoreLeft[i] + scoreRight[i] - height);
            // cout << scoreLeft[i] + scoreRight[i] << " " << height << endl;
        }
        return mx;
    }
};