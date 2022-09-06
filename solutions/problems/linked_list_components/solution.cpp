/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    vector<pair<int,int>> genVec(ListNode* head, int idx) {
        vector<pair<int,int>> v;
        if (head->next != nullptr) v = genVec(head->next,idx+1);
        v.push_back({head->val,idx});
        return v;
    }
    int numComponents(ListNode* head, vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<pair<int,int>> v = genVec(head,0);
        sort(v.begin(),v.end());
        vector<int> inds;
        for (int i : nums) {
            pair<int,int> p = {i,-1};
            auto it = std::lower_bound(v.begin(),v.end(),p);
            inds.push_back(it->second);
        }
        sort(inds.begin(),inds.end());
        //for (int i : inds) cout << i << " ";
        int idx = 1;
        bool cons = false;
        int groups = 0;
        while (idx < inds.size()) {
            if (inds[idx] != inds[idx-1] + 1) {
                groups++;
            }
            idx++;
            // if (cons) {
            //     if (inds[idx] != inds[idx-1] + 1) {
            //         cons = false;
            //         groups++;
            //     }
            //     else if (idx == inds.size()-1) groups++;
            // }
            // else {
            //     if (idx == inds.size()-1 || inds[idx] != inds[idx-1]) {
            //         groups++;
            //     }
            //     else cons = true;
            // }
            // idx++;
        }
        return groups+1;
    }
};