/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA, *ptrB = headB;
        int countA=0, countB=0;
        while(ptrA != NULL) {
            ptrA = ptrA->next;
            countA++;
        }
        while(ptrB != NULL) {
            ptrB = ptrB->next;
            countB++;
        }
        ptrA = headA, ptrB = headB;
        int moveFwd = countA-countB;
        if(moveFwd > 0) {
            while(moveFwd != 0) {
                ptrA = ptrA->next;
                moveFwd--;
            }
        } else {
            while(moveFwd != 0) {
                ptrB = ptrB->next;
                moveFwd++;
            }
        }
        while(ptrA != NULL && ptrB != NULL) {
            if(ptrA == ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return NULL;
    }
};
