class Solution {
public:
    string reverseWords(string s) {
        vector<int> spaces;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') spaces.push_back(i);
        }
        if (spaces.empty()) return s;
        vector<string> words;
        for (int i = 0; i < spaces.size(); i++) {
            if (i == 0) {
                if (spaces[0] != 0)words.push_back(s.substr(0,spaces[i]));
            }
            else if (spaces[i] > spaces[i-1]+1){
                words.push_back(s.substr(spaces[i-1]+1,spaces[i]-spaces[i-1]-1));
            }
        }
        if (spaces.back() != s.size()-1) words.push_back(s.substr(spaces.back()+1));
        reverse(words.begin(),words.end());
        string ret = "";
        for (int i = 0; i < words.size(); i++) {
            ret += words[i];
            if (i+1 != words.size()) ret +=" ";
        }
        return ret;

    }
};