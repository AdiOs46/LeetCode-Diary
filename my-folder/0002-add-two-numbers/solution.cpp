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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead, *t1 = l1, *t2 = l2;
        int sum=0, carry=0;
        while(t1 != NULL || t2 != NULL || carry != 0) {
            sum = carry;
            if(t1 != NULL) {
                sum += t1->val;
                t1 = t1->next;
            }
            if(t2 != NULL) {
                sum += t2->val;
                t2 = t2->next;
            }
            
            carry = sum/10;
            sum %= 10;

            ListNode* currAns = new ListNode(sum);
            temp->next = currAns;
            temp = currAns;
        }
        return newHead->next;
    }
};
