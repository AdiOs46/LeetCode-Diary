/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even; // Keep the head of the even list

    while (even != NULL && even->next != NULL) {
        odd->next = even->next; // Link the next odd node
        odd = odd->next;        // Move the odd pointer
        even->next = odd->next; // Link the next even node
        even = even->next;      // Move the even pointer
    }

    odd->next = evenHead; // Connect the end of odd list to the head of even list

    return head;
}
