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
        
        ListNode* prevHead = new ListNode(0);
        prevHead->next = head;
        ListNode* first = prevHead;
        ListNode* second = prevHead;

        int count = 0;
        while(count < n)
        {
            first = first->next;
            count++;
        }
        while(first->next)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return prevHead->next;
    }
};