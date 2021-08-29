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
        priority_queue< pair<int,pair<int,ListNode*>>, vector<pair<int,pair<int,ListNode*>>>, greater<pair<int,pair<int,ListNode*>>> > pq;
        //{value,{index,ListNode*}}
        ListNode* head = new ListNode();
        ListNode* nxt = new ListNode();
        bool firstTime = true;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) pq.push({lists[i]->val,{i,lists[i]}});
        }
        if (pq.empty()) return NULL;
        while (!pq.empty()) {
            pair<int,pair<int,ListNode*>> cur = pq.top();
            pq.pop();
            if (firstTime) {
                head = new ListNode(cur.first);
            }
            else {
                nxt->val = cur.first;
            }
            if (cur.second.second->next != NULL) {
                pq.push({cur.second.second->next->val,{cur.second.first,cur.second.second->next}});
            }
            if (!pq.empty()) {
                if (firstTime) {
                    head->next = nxt;
                    firstTime = false;
                }
                else {
                    nxt->next = new ListNode();
                    nxt = nxt->next;
                }
            }
        }
        return head;
    }
    
};