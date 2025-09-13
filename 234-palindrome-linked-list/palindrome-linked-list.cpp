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

    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp = head, *prev = NULL;
        while(temp)
        {
            ListNode* next1 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next1;
        }
        return prev; 
    }
    bool isPalindrome(ListNode* head) {
        
        if(!head->next)
            return true;

        ListNode* slow = findMid(head);
        ListNode* newhead = reverseList(slow->next);
        ListNode* node1 = newhead, *node2 = head;      
        while(node1 && node2)
        {
            if(node1->val!=node2->val)
                return false;
            node1 = node1->next;
            node2 = node2->next;
        }
        return true;
    }
};