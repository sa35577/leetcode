class KthLargest {
public:
    map<int,int> freq;
    int K;
    // set<pair<int,int>> s;
    multiset<int> s;
    KthLargest(int k, vector<int>& nums) {
        // for (int i : nums) {
        //     if (freq.find(i) != freq.end()) {
        //         freq[i] = 1;
        //     }
        //     else freq[i]++;
        // }
        // for (auto it = freq.begin(); it != freq.end(); it++) {
        //     s.insert(make_pair(it->second,it->first));
        // }
        for (int i : nums) {
            s.insert(i);
        }
        while (s.size() > k) {
            s.erase(s.begin());
        }
        K = k;
    }
    
    int add(int val) {
        // if (freq.find(val) == freq.end()) {
        //     freq[val] = 1;
        // }
        // else {
        //     s.erase(make_pair())
        //     freq[val]++;
        // }
        s.insert(val);
        if (s.size() > K) s.erase(s.begin());
        return *s.begin();


    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */