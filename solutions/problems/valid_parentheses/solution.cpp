class Solution {
public:
    bool isValid(string s) {
        deque<char> deck;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                deck.push_back(s[i]);
            }
            else {
                if (deck.size() == 0) return false;
                if (deck.back() == '(' && s[i] == ')') {
                    deck.pop_back();
                }
                else if (deck.back() == '{' && s[i] == '}') {
                    deck.pop_back();
                }
                else if (deck.back() == '[' && s[i] == ']') {
                    deck.pop_back();
                }
                else return false;
            }
        }
        return (deck.size() == 0);
    }
};