class Solution {
public:
    vector<vector<int>> powerGen(vector<int> rem) {
        vector<vector<int>> v;
        if (rem.size() == 0) {
            vector<int> empty;
            v.push_back(empty);
            return v;
        }
        int idx = 0, rightptr = 0;
        
        rightptr = idx;
        while (rightptr+1 < rem.size() && rem[idx] == rem[rightptr+1]) ++rightptr;
        //cout << idx <<  " " << rightptr << endl;

        vector<int> remRec = rem;
        for (int j = 0; j <= rightptr-idx; j++) remRec.erase(remRec.begin()+idx);
        vector<vector<int>> recResult = powerGen(remRec);
        v.insert(v.end(),recResult.begin(),recResult.end());

        for (int i = 0; i <= rightptr - idx; i++) {    
            vector<int> newContents;
            for (int j = 0; j <= i; j++) newContents.push_back(rem[idx]);

            for (vector<int> w : recResult) {
                w.insert(w.end(),newContents.begin(),newContents.end());
                v.push_back(w);
            }
            
        }
        return v;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res = powerGen(nums);
        return res;
        // vector<vector<int>> ret;
        // vector<int> empty;
        // ret.push_back(empty);
        // for (vector<int> v : res) {
        //     if (v.size() > 0) ret.push_back(v);
        // }
        // return ret;
    }
};