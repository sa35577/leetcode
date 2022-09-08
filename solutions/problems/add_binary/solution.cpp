class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> v;
        int carry = 0;
        int i1 = a.size()-1, i2 = b.size()-1;
        while (i1 > -1 || i2 > -1) {
            int res = carry;
            if (i2 >= 0) res += (b[i2]-'0');
            if (i1 >= 0) res += (a[i1]-'0');
            if (res % 2 == 0) {
                v.push_back('0');
            }
            else {
                v.push_back('1');
            }
            carry = (res/2);
            i1--;
            i2--;
        }
        if (carry == 1) v.push_back('1');
        string s = "";
        for (int i = v.size()-1; i >= 0; i--) s += v[i];
        return s;
    }
};