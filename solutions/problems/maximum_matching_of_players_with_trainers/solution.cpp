class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int P = 0, T = 0;
        int cnt = 0;
        while (P < players.size() && T < trainers.size()) {
            while (T < trainers.size() && players[P] > trainers[T]) T++;
            if (T == trainers.size()) break;
            cnt++;
            P++;
            T++;
        }
        return cnt;
    }
};