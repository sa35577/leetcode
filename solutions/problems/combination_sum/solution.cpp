class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> oldwaystocombine[41];
        vector<vector<int>> newwaystocombine[41];
        vector<int> emp;
        oldwaystocombine[0].push_back(emp);
        newwaystocombine[0].push_back(emp);
        for (int candidate : candidates) {
            // for (int i = 0; i <= 40; i++) {
            //     cout << i << ": " << oldwaystocombine[i].size() << endl;
            // }
            // for (int i = 0; i <= 40; i++) {
            //     cout << i << ": " << oldwaystocombine[i].size() << endl;
            // }
            for (int i = 0; i < target; i++) {
                int mult = 1;
                vector<int> newstuff;
                while (i + candidate * mult <= target) {
                    newstuff.push_back(candidate); //at every point, contains exactly mult number of times
                    for (vector<int> v : oldwaystocombine[i]) {
                        v.insert(v.end(),newstuff.begin(),newstuff.end());
                        newwaystocombine[i + candidate * mult].push_back(v);
                    }
                    mult++;
                }
                
            }
            for (int i = 0; i <= 40; i++) {
                oldwaystocombine[i] = newwaystocombine[i];
            }
        }
        return oldwaystocombine[target];
    }
};