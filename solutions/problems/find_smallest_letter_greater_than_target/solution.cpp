#include <algorithm>
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        vector<int> v;
        for (char c : letters) v.push_back(c-'a');
        letters.push_back(letters[0]);
        //for (int i : v) cout << i << " ";
        int x = target - 'a';
        int res = std::upper_bound(v.begin(),v.end(),x) - v.begin();
        return letters[res];
    }
};