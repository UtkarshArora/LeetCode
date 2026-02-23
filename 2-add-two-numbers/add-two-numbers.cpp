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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0;
        int carry = 0;
        ListNode* prev = new ListNode();
        ListNode* curr = prev;
        while(l1 && l2)
        {
            int s1 = l1->val + l2->val + carry;
            sum = s1%10;
            carry = s1/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int s1 = l1->val + carry;
            sum = s1%10;
            carry = s1/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int s1 = l2->val + carry;
            sum = s1%10;
            carry = s1/10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l2 = l2->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return prev->next;
    }
};