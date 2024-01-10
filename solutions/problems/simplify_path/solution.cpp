class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        vector<int> dataType;
        //0: slash, 1: current directory, -1: backward directory, 2: path
        int L = 0;
        while (L < path.size()) {
            if (path[L] == '/') {
                int R = L;
                while (R < path.size() && path[R] == '/') R++;
                string slash = "/";
                tokens.push_back(slash);
                L = R;
                dataType.push_back(0);
            }
            else if (path[L] == '.') {
                int R = L;
                while (R < path.size() && path[R] != '/') R++;
                if (R-L == 1) {
                    tokens.push_back(".");
                    dataType.push_back(1);
                }
                else if (R-L == 2 && path[L+1] == '.') {
                    tokens.push_back("..");
                    dataType.push_back(-1);
                }
                else {
                    tokens.push_back(path.substr(L,R-L));
                    dataType.push_back(2);
                }
                L = R;
            }
            else {
                int R = L;
                while (R < path.size() && path[R] != '/') R++;
                tokens.push_back(path.substr(L,R-L));
                L = R;
                dataType.push_back(2);
            }
        }
        stack<string> stck;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            int data = dataType[i];
            if (data == 0) ;
            else if (data == 1) {
                ;
            }
            else if (data == -1) {
                if (!stck.empty()) stck.pop();
            }
            else {
                stck.push(token);
            }
        }
        stack<string> stckrev;
        while (!stck.empty()) {
            stckrev.push(stck.top());
            stck.pop();
        }
        string res = "";
        if (stckrev.empty()) return "/";
        while (!stckrev.empty()) {
            res += '/';
            res += stckrev.top();
            stckrev.pop();
        }
        return res;
        
    }
};