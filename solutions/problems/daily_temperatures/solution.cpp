class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        fill(answer.begin(),answer.end(),0);
        stack<int> stck;
        stck.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!stck.empty() && temperatures[stck.top()] < temperatures[i]) {
                answer[stck.top()] = i - stck.top();
                stck.pop();
            }
            stck.push(i);
        }
        return answer;
    }
};