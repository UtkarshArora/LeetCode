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
        
        if(!head || !head->next)
            return head;
        
        ListNode* newhead = head->next;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr && curr->next)
        {
            ListNode* next1 = curr->next;
            curr->next = next1->next;
            next1->next = curr;
            if(prev != NULL)
                prev->next = next1;
            prev = curr;
            curr = curr->next;
        }
        return newhead;
    }
};