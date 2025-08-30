/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    stack<Node*> levels;
    Node* flatten(Node* head) {

        Node* newhead = head;
        Node* curr = head;
        Node* tail = head;

        while(curr) {
            if (curr->child!=NULL){
                if(curr->next!=NULL)
                    levels.push(curr->next);
                curr = curr->child;
                curr->prev = tail;
                tail->next = curr;
                tail->child = NULL;
                tail = tail->next;
            } else if (curr->next) {
                curr = curr->next;
                curr->prev = tail;
                tail->next = curr;
                tail->child = NULL;
                tail = tail->next;
            } else {
                //cout<<"tail:"<<tail->val<<endl;
                if(levels.empty())
                    return newhead;
                curr = levels.top();
                levels.pop();
                tail->next = curr;
                curr->prev = tail;
                tail = curr;
                tail->child = NULL;
            }
        }
        return newhead;
    }
};