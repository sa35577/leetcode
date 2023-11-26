class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> v1;
        for (int i = 0; i < values.size(); i++) {
            v1.push_back(values[i]-i);
        }
        reverse(v1.begin(),v1.end());
        vector<int> psa{v1[0]};
        for (int i = 1; i < v1.size(); i++) {
            psa.push_back(max(psa.back(),v1[i]));
        }
        reverse(psa.begin(),psa.end());
        int mx = -500000;
        for (int i = 0; i < values.size()-1; i++) {
            mx = max(mx,values[i]+i+psa[i+1]);
        }
        return mx;

    }
};