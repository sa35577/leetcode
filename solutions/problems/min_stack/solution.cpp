class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> stck;
    MinStack() {
        
    }
    
    void push(int val) {
        if (stck.empty()) {
            stck.push({val,val});
        }
        else {
            int curMin = stck.top().second;
            stck.push({val,min(curMin,val)});
        }
    }
    
    void pop() {
        stck.pop();
    }
    
    int top() {
        return stck.top().first;
    }
    
    int getMin() {
        return stck.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */