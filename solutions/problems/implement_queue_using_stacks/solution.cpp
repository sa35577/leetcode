class MyQueue {
public:
    stack<int> stck;
    MyQueue() {
        
    }
    
    void push(int x) {
        stck.push(x);
    }
    
    int pop() {
        stack<int> stck2;
        while (!stck.empty()) {
            stck2.push(stck.top());
            stck.pop();
        }
        int x = stck2.top();
        stck2.pop();
        while (!stck2.empty()) {
            stck.push(stck2.top());
            stck2.pop();
        }
        return x;
    }
    
    int peek() {
        stack<int> stck2;
        while (!stck.empty()) {
            stck2.push(stck.top());
            stck.pop();
        }
        int x = stck2.top();
        // stck2.pop();
        while (!stck2.empty()) {
            stck.push(stck2.top());
            stck2.pop();
        }
        return x;
    }
    
    bool empty() {
        return stck.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */