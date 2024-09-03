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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        //find the middle node
        ListNode* slow = head, *fast = head;
        ListNode* slowprev = head;
        while(fast && fast->next) {
            slowprev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //delete middle node
        slowprev->next = slow->next;
        slow->next = nullptr;
        return head;
    }
};
