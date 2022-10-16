class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            vector<string> v;
            return v;
        }
        char let1 = 'a';
        switch (digits[0]) {
            case '3':
                let1 = 'd';
                break;
            case '4':
                let1 = 'g';
                break;
            case '5':
                let1 = 'j';
                break;
            case '6':
                let1 = 'm';
                break;
            case '7':
                let1 = 'p';
                break;
            case '8':
                let1 = 't';
                break;
            case '9':
                let1 = 'w';
                break;
            default:
                break;
        }
        char let2 = let1+1;
        char let3 = let2+1;
        char let4 = let3+1;
        string s1 = "", s2 = "", s3 = "", s4 = "";
        s1 += let1;
        s2 += let2;
        s3 += let3;
        s4 += let4;
        vector<string> v;
        if (digits.size() == 1) {
            v.push_back(s1);
            v.push_back(s2);
            v.push_back(s3);
            if (digits[0] == '7' || digits[0] == '9') v.push_back(s4);
            return v;
        }
        vector<string> rec = letterCombinations(digits.substr(1));
        for (string s : rec) {
            v.push_back(s1+s);
            v.push_back(s2+s);
            v.push_back(s3+s);
            if (digits[0] == '7' || digits[0] == '9') v.push_back(s4+s);
        }
        return v;
    }
};