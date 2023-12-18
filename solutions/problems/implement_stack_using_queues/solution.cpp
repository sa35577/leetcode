class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int ans = -1;
        int cnt = 0;
        while (!q1.empty()) {
            q2.push(q1.front());
            ans = q1.front();
            q1.pop();
            cnt++;
        }
        while (cnt > 1) {
            q1.push(q2.front());
            // cout << q2.front() << " " ;
            q2.pop();
            cnt--;
        }
        // cout << "Popped: " << q2.front();
        q2.pop();
        // cout << "\n";
        return ans;
    }
    
    int top() {
        int ans = -1;
        int cnt = 0;
        while (!q1.empty()) {
            q2.push(q1.front());
            ans = q1.front();
            q1.pop();
            cnt++;
        }
        while (cnt > 0) {
            q1.push(q2.front());
            // cout << q2.front() << " " ;
            q2.pop();
            cnt--;
        }
        // q2.pop();
        // cout << "\n";
        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */