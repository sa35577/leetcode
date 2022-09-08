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
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int cnt = 0;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                cnt++;
                pq.push(make_pair(lists[i]->val,i));
            }
        }
        ListNode* head = nullptr, *cur = nullptr;
        while (cnt > 0) {
            pair<int,int> p = pq.top();
            pq.pop();
            //cout << p.first << " ";
            if (head == nullptr) {
                head = lists[p.second];
                cur = head;
            }
            else {
                cur->next = lists[p.second];
                cur = cur->next;
            }
            lists[p.second] = lists[p.second]->next;
            if (lists[p.second] == nullptr) cnt--;
            else {
                pq.push(make_pair(lists[p.second]->val,p.second));
            }
            cur->next = nullptr;
        }
        return head;
    }
};