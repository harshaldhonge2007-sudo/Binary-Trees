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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* temp = head->next;
        ListNode* prev = head;

        while (temp != nullptr) {
            // Already in the correct position
            if (prev->val <= temp->val) {
                prev = temp;
                temp = temp->next;
                continue;
            }

            // Find the insertion position
            ListNode* temp2 = &dummy;

            while (temp2->next != temp &&
                   temp2->next->val <= temp->val) {
                temp2 = temp2->next;
            }

            // Remove temp from its current position
            prev->next = temp->next;

            // Insert temp at the correct position
            temp->next = temp2->next;
            temp2->next = temp;

            // Continue with the next unsorted node
            temp = prev->next;
        }

        return dummy.next;
    }
};
