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
        int carry = 0;
        ListNode* it1 = l1, *it2 = l2;
        ListNode* newHead = new ListNode();
        ListNode* prev = new ListNode();
        newHead = prev;


        while(it1 || it2 || carry) {
            ListNode* newNode = new ListNode();
            prev->next = newNode;

            int sum = carry;
            if (it1) {
                sum += it1->val;
                it1 = it1->next;
            }

            if (it2) {
                sum += it2->val;
                it2 = it2->next;
            }

            newNode->val = sum % 10;
            carry = sum / 10;

            prev = newNode;
        }

        return newHead->next;
    }
};
