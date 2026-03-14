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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        if(k == 0)
            return NULL;
        ListNode* prev = new ListNode();
        ListNode* tail = new ListNode();
        prev->next = tail;
        while(1)
        {
            int minVal = INT_MAX;
            int minIndex = -1;
            bool added = false;
            for(int i = 0 ; i < k ; i++)
            {
                if(lists[i] == NULL){
                    continue;
                }
                if(lists[i]->val < minVal)
                {
                    minVal = lists[i]->val;
                    minIndex = i;
                    added = true;
                }
            }
            if(added)
                {
                    tail->next = lists[minIndex];
                    tail = tail->next;
                    lists[minIndex] = lists[minIndex]->next;
                }
            else
                {
                    break;
                }
        }
        return prev->next->next;
    }
};