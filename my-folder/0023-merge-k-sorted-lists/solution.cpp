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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<lists.size(); i++) {
            ListNode* mover = lists[i];
            while(mover != NULL) {
                pq.push(mover->val);
                mover = mover->next;
            }
        }

        if(pq.empty()) return NULL;

        ListNode* newHead = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = newHead;

        while(!pq.empty()) {
            ListNode* curr = new ListNode(pq.top());
            temp->next = curr;
            temp = curr;
            pq.pop();
        }
        return newHead;
    }
};
