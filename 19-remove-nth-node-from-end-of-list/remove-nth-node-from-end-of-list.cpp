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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        int count = 0;
        if(n == 1 && !head->next)
            return NULL;
        while(count < n && first)
        {
            first = first->next;
            count++;
        }
        if(first == NULL){
            head = head->next;
            return head;
        }
        ListNode* second = head;
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
    }
    
};