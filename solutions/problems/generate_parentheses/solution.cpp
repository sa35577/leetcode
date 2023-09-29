class Solution {
public:
    vector<string> generate(int leftParen, int rightParen) {
        vector<string> res;
        string s = "";
        if (leftParen == 0 && rightParen == 0) {
            res.push_back(s);
            return res;
        }
        else if (rightParen == 0) return res; //we used all of our closures
        if (leftParen != 0) {
            s = "(";
            vector<string> rec = generate(leftParen-1,rightParen);
            for (int i = 0; i < rec.size(); i++) {
                res.push_back(s + rec[i]);
            }
        }
        if (rightParen > leftParen) {
            s = ")";
            vector<string> rec = generate(leftParen,rightParen-1);
            for (int i = 0; i < rec.size(); i++) {
                res.push_back(s + rec[i]);
            }
        }
        return res;

    }
    vector<string> generateParenthesis(int n) {
        return generate(n,n);
    }
};