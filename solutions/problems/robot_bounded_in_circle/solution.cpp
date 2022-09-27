class Solution {
public:
    bool isRobotBounded(string instructions) {
        int netTurn = 0;
        for (int i = 0; i < instructions.size(); i++) {
            if (instructions[i] == 'L') netTurn++;
            else if (instructions[i] == 'R') netTurn--;
        }
        int numCycles = 1;
        if (netTurn < 0) netTurn = -netTurn;
        if (netTurn % 4 == 2) numCycles = 2;
        if (netTurn % 2 == 1) numCycles = 4;
        //cout << netTurn << " " << numCycles << endl;
        int sz = instructions.size();
        for (int i = 0; i < sz; i++) {
            int y = 0, x = 0, dir = 1;
            for (int j = 0; j < sz * numCycles; j++) {
                if (instructions[(j+i) % sz] == 'G') {
                    if (dir == 1) y++;
                    else if (dir == 2) x--;
                    else if (dir == 3) y--;
                    else if (dir == 0) x++;
                }
                else if (instructions[(j+i) % sz] == 'L') {
                    dir = (dir + 1) % 4;
                }
                else {
                    dir = ((dir - 1) + 4) % 4;
                }
            }
            if (y == 0 && x == 0 && dir == 1) return true;
        }
        return false;
    }
};