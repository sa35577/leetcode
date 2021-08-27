class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> hashSet;
    MyHashSet() {
        hashSet.resize(1000005);
    }
    
    void add(int key) {
        hashSet[key] = 1;
    }
    
    void remove(int key) {
        hashSet[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */