/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*>clones;
    Node* copyRandomList(Node* head) {

        if(head == NULL){
            return NULL;
        }
        if(clones.find(head)!=clones.end())
        {
            return clones[head];
        }
        Node* newHead = new Node(head->val);
        clones[head] = newHead;
        newHead->next = copyRandomList(head->next);
        newHead->random = copyRandomList(head->random);
        return newHead;
    }   
};