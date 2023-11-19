class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        vector<int> v1,v2;
        int a = left, b = right;
        for (int i = 0; i < 32; i++) {
            if (a % 2 == 0) v1.push_back(0);
            else v1.push_back(1);
            if (b % 2 == 0) v2.push_back(0);
            else v2.push_back(1);
            a /= 2;
            b /= 2;
            
        }   
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        // for (int i : v1 ) cout << i << " " ;
        // cout << "\n";
        // for (int i : v2 ) cout << i << " " ;
        int ptr = 0;
        while (ptr < v1.size() && v1[ptr] == v2[ptr]) ++ptr;
        ptr--;
        int sum = 0;
        while (ptr >= 0) {
            sum += (1 << (31-ptr)) * v1[ptr];
            ptr--;
        }
        return sum;
    }
};