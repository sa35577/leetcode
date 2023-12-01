struct MyStruct
{
    string s;

    MyStruct(const std::string& s) : s(s) {}
};

struct less_than_key
{
    inline bool operator() (const MyStruct& struct1, const MyStruct& struct2)
    {
        string s1 = struct1.s, s2 = struct2.s;
        unsigned long long x = 0, y = 0;
        for (char c : s1) {
            x = (unsigned long long)(x * 10LL) + (unsigned long long)(c - '0');
        }
        for (char d : s2) {
            x = (unsigned long long)(x * 10LL) + (unsigned long long)(d - '0');
            y = (unsigned long long)(y * 10LL) + (unsigned long long)(d - '0');
        }
        for (char c : s1) {
            y = (unsigned long long)(y * 10LL) + (unsigned long long)(c - '0');
        }
        return y > x;
        // if (s1 == s2) return false;
        // for (int i = 0; i < min(s1.size(),s2.size()); i++) {
        //     if (s1[i] != s2[i]) return s1[i] < s2[i];
        // }
        // if (s1.size() < s2.size()) {
        //     int ptr = s1.size();
        //     while (ptr < s2.size() && s1[0] == s2[ptr]) ptr++;
        //     if (ptr == s2.size()) return false;
        //     return s1[0] >= s2[ptr];
        // }
        // else {
        //     int ptr = s2.size();
        //     while (ptr < s1.size() && s2[0] == s1[ptr]) ptr++;
        //     if (ptr == s1.size()) return false;
        //     return s2[0] >= s1[ptr];
        // }
    
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<MyStruct> v;
        for (int x : nums) {
            v.push_back(MyStruct(to_string(x)));
        }
           
        sort(v.begin(),v.end(), less_than_key());
        reverse(v.begin(),v.end());
        string s = "";
        for (MyStruct t : v) {
            s += t.s;
        }
        int ptr = 0;
        // return "adsf";
        while (ptr < s.size() && s[ptr] == '0') {
            ++ptr;
        }
        if (ptr == s.size()) return "0";
        return s.substr(ptr);
    }
};