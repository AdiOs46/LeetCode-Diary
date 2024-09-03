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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0 || !head->next) return head;

        int n = 1;
        ListNode* temp = head;
        while(temp->next) {
            n++;
            temp = temp->next;
        }

        k = k % n;
        if (k == 0) return head; 

        int goTill = n - k;
        ListNode* partition_point = head;

        for(int i=1; i<goTill; i++) {
            partition_point = partition_point->next;
        }

        ListNode* prev = partition_point;
        partition_point = partition_point->next;
        prev->next = nullptr;

        temp->next = head;

        return partition_point;
    }
};
