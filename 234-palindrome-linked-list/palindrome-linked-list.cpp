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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        if(!head->next)
            return true;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next, *prev = NULL;
        slow->next = NULL;
        while(temp)
        {
            ListNode* next1 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next1;
        }
        ListNode* newhead = prev;  
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