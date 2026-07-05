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

    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if (l1 != nullptr)
            tail->next = l1;

        if (l2 != nullptr)
            tail->next = l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two halves
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge sorted halves
        return merge(left, right);
    }
};