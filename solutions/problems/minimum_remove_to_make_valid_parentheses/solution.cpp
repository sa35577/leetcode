class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        int numLeft = 0;
        int numRight = 0;
        for (char c : s) {
            if (c == '(') numLeft++;
            else if (c == ')') numRight++;
        }
        if (numLeft > numRight) {
            reverse(s.begin(),s.end());
            for (char c : s) {
                if (c == '(' && numLeft > numRight) {
                    numLeft--;
                }
                else res += c;
            }
            reverse(res.begin(),res.end());
            s = res;
            res = "";
        }
        else if (numLeft < numRight) {
            for (char c : s) {
                if (c == ')' && numLeft < numRight) {
                    numRight--;
                }
                else res += c;
            }
            s = res;
            res = "";
        }
        //at this point, the number of left and right brackets should be the same
        int balance = 0;
        int numDelete = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
                res += c;
            }
            else if (c == ')') {
                if (balance == 0) {
                    numDelete++;
                }
                else {
                    balance--;
                    res += c;
                }
            }
            else {
                res += c;
            }
        }
        s = res;
        res = "";
        reverse(s.begin(),s.end());
        for (char c : s) {
            if (c == '(' && numDelete > 0) {
                numDelete--;
            }
            else res += c;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};