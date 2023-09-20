class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> left,right;
        int n = nums.size();
        int leftptr = -1, rightptr = n;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left.push_back(nums[0]);
                right.push_back(nums.back());
            }
            else {
                left.push_back(left.back()+nums[i]);
                right.push_back(right.back() + nums[nums.size()-1-i]);
            }
            if (left.back() <= x) leftptr++;
        }
        reverse(right.begin(),right.end());
        int mnAns = 2*nums.size();
        while (leftptr >= 0) {
            int rem = x - left[leftptr];
            if (rem == 0) {
                mnAns = min(mnAns,leftptr-0+1);
            }
            else {
                if (rightptr == n) {
                    if (n-1 > leftptr && rem >= right[n-1]) {
                        rightptr--;
                        while (rightptr-1 > leftptr && rem >= right[rightptr-1] && rem > right[rightptr]) {
                            rightptr--;
                        }
                        if (rem == right[rightptr]) mnAns = min(mnAns,leftptr-0+1 + (n-1)-rightptr+1);
                    }
                    else {
                        ; //impossible to find combo
                    }
                }
                else {
                    while (rightptr-1 > leftptr && rem >= right[rightptr-1] && rem > right[rightptr]) {
                        rightptr--;
                    }
                    if (rem == right[rightptr]) mnAns = min(mnAns,leftptr-0+1 + (n-1)-rightptr+1);
                }
            }
            cout << leftptr << " " << rightptr << " " << rem << endl;
            leftptr--;
        }
        while (rightptr > -1 && (rightptr == n || right[rightptr] < x)) rightptr--;
        if (rightptr != -1 && rightptr != n && right[rightptr] == x) {
            mnAns = min(mnAns,(n-1) - rightptr + 1);
        }
        if (mnAns == 2*n) return -1;
        return mnAns;
    }
};