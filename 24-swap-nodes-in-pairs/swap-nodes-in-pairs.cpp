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
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* next1 = curr->next;
            curr->next = next1->next;
            next1->next = curr;
            prev->next = next1;
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};