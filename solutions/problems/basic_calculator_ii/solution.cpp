class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;
        int L = 0;
        while (L < s.size()) {
            if (s[L] >= '0' && s[L] <= '9') {
                int R = L;
                while (R+1 < s.size() && s[R+1] >= '0' && s[R+1] <= '9') R++;
                nums.push_back(stoi(s.substr(L,R-L+1)));
                L = R+1;
            }
            else if (s[L] == '+' || s[L] == '*' || s[L] == '/' || s[L] == '-') {
                ops.push_back(s[L]);
                L++;
            }
            else {
                L++;
            }
        }
        // forward pass for mult / div
        // for (int i : nums) cout << i << " ";
        // for (char c : ops) cout << c << " ";
        cout << nums.size() << endl;
        cout << ops.size() << endl;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '*') {
                if (i != 0) ops[i] = ops[i-1];
                else ops[i] = '+';
                nums[i+1] = nums[i] * nums[i+1];
                nums[i] = 0;
            }
            else if (ops[i] == '/') {
                if (i != 0) ops[i] = ops[i-1];
                else ops[i] = '+';
                nums[i+1] = nums[i] / nums[i+1];
                nums[i] = 0;
            }
        }
        // full pass
        // for (int i : nums) cout << i << " ";
        // for (char c : ops) cout << c << " ";
        // return 3;
        // cout << nums[0];
        for (int i = 0; i < ops.size(); i++) {
            cout << ops[i] << " " << nums[i+1];
        }
        int x = nums[0];
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '+') x += nums[i+1];
            else if (ops[i] == '-') x -= nums[i+1];
        }
        return x;
    }
};