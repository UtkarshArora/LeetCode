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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }
    void mergeLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = list1, *tail = list1;
        ListNode* curr1 = list1->next, *curr2 = list2;
        bool listNum = false;
        while(curr1 && curr2)
        {
            if(listNum)
            {
                tail->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                tail->next = curr2;
                curr2 = curr2->next;
            }
            listNum = !listNum;
            tail = tail->next;
        }
        if(curr1)
        {
            tail->next = curr1;
        }
        else
        {
            tail->next = curr2;
        }
        return;
    }
    void reorderList(ListNode* head) {
        
        if(!head->next)
            return;
        
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;
        ListNode* reversed = reverseList(list2);
        //merge logic now
        mergeLists(head, reversed);
        return;
    }
};