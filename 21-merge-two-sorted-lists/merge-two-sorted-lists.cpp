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

    ListNode* merge(ListNode* list1, ListNode* list2, ListNode* curr)
    {
        if(!list1){
            curr->next = list2;
            curr = curr->next;
            return curr;
        }
        if(!list2){
            curr->next = list1;
            curr = curr->next;
            return curr;
        }
        if(list1->val < list2->val)
        {
            curr->next = list1;
            curr = curr->next;
            curr->next = merge(list1->next, list2, curr);
        }
        else
        {
            curr->next = list2;
            curr = curr->next;
            curr->next = merge(list1, list2->next, curr);
        }
        return curr;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* prev = new ListNode();
        ListNode* curr = prev;
        merge(list1, list2, curr);
        return prev->next;
    }
};