class ProductOfNumbers {
public:
    vector<int> stream;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) stream.clear();
        else if (stream.size() == 0) stream.push_back(num);
        else stream.push_back(stream.back()*num);
    }
    
    int getProduct(int k) {
        if (stream.size() < k) return 0;
        if (stream.size() == k) return stream.back();
        int idx = stream.size()-k-1;
        return stream.back()/stream[idx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */