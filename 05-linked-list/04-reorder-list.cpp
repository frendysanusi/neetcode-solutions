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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* list1 = head;
        ListNode* list2 = prev;
        while (list1 && list2) {
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            list2->next = list1->next;
            list1->next = list2;
            list1 = temp1;
            list2 = temp2;
        }
    }
};
