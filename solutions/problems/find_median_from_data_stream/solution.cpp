class MedianFinder {
public:
    priority_queue<int,vector<int>> leftSide; //greatest on top
    priority_queue<int,vector<int>,greater<int>> rightSide; //least on top
    int med;
    MedianFinder() {
        med = -1000000;
    }
    
    void addNum(int num) {
        if (med == -1000000) {
            if (leftSide.size() == 0 || (num >= leftSide.top() && num <= rightSide.top()))
                med = num;
            else if (num < leftSide.top()) {
                med = leftSide.top();
                leftSide.pop();
                leftSide.push(num);
            }
            else {
                med = rightSide.top();
                rightSide.pop();
                rightSide.push(num);
            }
        }
        else {
            if (num >= med) {
                rightSide.push(num);
                leftSide.push(med);
            }
            else {
                rightSide.push(med);
                leftSide.push(num);
            }
            med = -1000000;
            
            while (leftSide.size() > rightSide.size() + 1) {
                rightSide.push(leftSide.top());
                leftSide.pop();
            }
            while (rightSide.size() > leftSide.size() + 1) {
                leftSide.push(rightSide.top());
                rightSide.pop();
            }
        }
    }
    
    double findMedian() {
        double res = 0;
        if (med != -1000000) {
            res = (double)med;
            return res;
        }
        res = (leftSide.top() + rightSide.top())/2.0;
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */