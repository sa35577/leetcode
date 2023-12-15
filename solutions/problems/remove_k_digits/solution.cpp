class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        deque<char> deck;
        deck.push_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            // bool replace = false;
            while (!deck.empty() && k > 0 && deck.back() > num[i]) {
                deck.pop_back();
                k--;
                // replace = true;
            }
            deck.push_back(num[i]);            
            if (k == 0) {
                for (int j = i+1; j < num.size(); j++) deck.push_back(num[j]);
                break;
            }
        }

        while (k > 0) {
            deck.pop_back();
            k--;
        }
        while (!deck.empty() && deck.front() == '0') deck.pop_front();
        string ret = "";
        while (!deck.empty()) {
            ret += deck.front();
            deck.pop_front();
        }
        if (ret == "") return "0";
        return ret;

    }
};