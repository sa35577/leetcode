class DataStream {
public:
    int prev = -1, cnt = 0;
    int K;
    int v;
    DataStream(int value, int k) {
        prev = -1;
        K = k;
        cnt = 1;
        v = value;
    }
    
    bool consec(int num) {
        if (prev == num) cnt++;
        else {
            prev = num;
            cnt = 1;
        }
        return cnt >= K && prev == v;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */