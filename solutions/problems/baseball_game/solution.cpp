#include <deque>
#include <string>
class Solution {
public:
    int calPoints(vector<string>& ops) {
        deque<int> deck;
        long long sum = 0;
        for (string op : ops) {
            if (op == "C") {
                sum -= deck.back();
                deck.pop_back();
            }
            else if (op == "D") {
                deck.push_back(deck.back()*2);
                sum += deck.back();
            }
            else if (op == "+") {
                int p1 = deck.back();
                deck.pop_back();
                int res = p1 + deck.back();
                deck.push_back(p1);
                deck.push_back(res);
                sum += res;
            }
            else {
                deck.push_back(stoi(op));
                sum += deck.back();
            }
        }  
        return (int)sum;
    }
};