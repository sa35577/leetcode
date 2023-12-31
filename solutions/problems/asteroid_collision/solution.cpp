class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stck;
        int idx = 0;
        vector<int> res;
        while (idx < asteroids.size()) {
            if (stck.empty()) {
                while (idx < asteroids.size() && asteroids[idx] < 0) {
                    res.push_back(asteroids[idx++]);
                }
                if (idx == asteroids.size()) break;
            }
            if (asteroids[idx] > 0) {
                stck.push(asteroids[idx++]);
            }
            else {
                while (!stck.empty() && stck.top() < -asteroids[idx]) stck.pop();
                if (stck.empty()) {
                    ; //on next iteration, add to res
                }
                else {
                    if (stck.top() == -asteroids[idx]) {
                        stck.pop(); //tie
                        idx++;
                    }
                    else {
                        idx++; //top of stack won
                    }
                }
            }
        }   
        vector<int> rem;
        while (!stck.empty()) {
            rem.push_back(stck.top());
            stck.pop();
        }
        reverse(rem.begin(),rem.end());
        res.insert(res.end(),rem.begin(),rem.end());
        return res;

    }
};