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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* newHead = NULL;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing portion after slow ptr
        ListNode* prev = NULL, *fwd=NULL, *curr=slow;
        while(curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        newHead = prev;
        ListNode* temp1=head, *temp2=newHead;
        //comparing
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    
        return true;
    }
};
