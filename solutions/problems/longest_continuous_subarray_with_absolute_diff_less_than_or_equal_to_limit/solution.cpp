class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int L = 0, R = 0;
        
        st.insert(nums[0]);
        while (R+1 < nums.size() && nums[R+1] <= *(st.begin()) + limit && nums[R+1] >= *(st.rbegin()) - limit) {
            st.insert(nums[R+1]);
            R++;
        } 
        int maxsz = R-L+1;
        cout << L << " " << R << endl;
        while (R < nums.size()-1) {
            while (!st.empty() && (nums[R+1] < *(st.rbegin()) - limit || nums[R+1] > *(st.begin()) + limit)) {
                st.erase(st.lower_bound(nums[L]));
                L++;
            }
            st.insert(nums[R+1]);
            R++;
            cout << L << " " << R << endl;
            while (R+1 < nums.size() && nums[R+1] <= *(st.begin()) + limit && nums[R+1] >= *(st.rbegin()) - limit) {
                st.insert(nums[R+1]);
                R++;
            } 
            cout << L << " " << R << endl;
            maxsz = max(maxsz,R-L+1);
        }
        return maxsz;
    }
};