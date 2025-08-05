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
    ListNode* deleteMiddle(ListNode* head) {

        ListNode* slow = head, *fast = head, *prev = NULL;

        if(head->next == NULL)
            return NULL;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // fast = head;
        // while(fast->next!=slow)
        // {
        //     fast = fast->next;
        // }
        // fast->next = fast->next->next;
        // return head;
        prev->next = prev->next->next;
        return head;
    }
};