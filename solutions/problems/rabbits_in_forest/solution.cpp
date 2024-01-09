class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for (int answer : answers) {
            if (mp.find(answer) == mp.end()) mp[answer] = 1;
            else mp[answer]++;
        }
        int score = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int key = it->first, val = it->second;
            while (val > key+1) {
                score += key+1;
                val -= key+1;
            }
            score += key+1;
            // cout << score << endl;
        }
        return score;
    }
};