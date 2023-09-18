class Solution {
public:
    int evalBack(vector<string>& tokens) {
        if (tokens.back() == "+") {
            tokens.pop_back();
            int s1 = evalBack(tokens);
            int s2 = evalBack(tokens);
            return s2 + s1;
        }
        else if (tokens.back() == "-") {
            tokens.pop_back();
            int s1 = evalBack(tokens);
            int s2 = evalBack(tokens);
            return s2 - s1;
        }
        else if (tokens.back() == "*") {
            tokens.pop_back();
            int s1 = evalBack(tokens);
            int s2 = evalBack(tokens);
            return s2 * s1;
        }
        else if (tokens.back() == "/") {
            tokens.pop_back();
            int s1 = evalBack(tokens);
            int s2 = evalBack(tokens);
            return s2 / s1;
        }
        else {
            int res = stoi(tokens.back());
            tokens.pop_back();
            return res;
        }
    }

    int evalRPN(vector<string>& tokens) {
        return evalBack(tokens);
    }
};