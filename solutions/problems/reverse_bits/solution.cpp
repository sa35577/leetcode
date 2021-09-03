class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //return INT32_MAX;
        uint32_t k = 0;
        for (int i = 0; i < 32; i++) {
            k <<= 1;
            k += (n%2);
            n >>= 1;
        }
        return k;
    }
};