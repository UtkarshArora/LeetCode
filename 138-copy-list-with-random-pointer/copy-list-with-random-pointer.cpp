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
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*>clones;
        Node* node = head;
        while(node)
        {
            Node* newNode = new Node(node->val);
            clones[node] = newNode;
            node = node->next;
        }
        node = head;
        while(node)
        {
            Node* newNode = clones[node];
            newNode->next = node->next? clones[node->next] : NULL;
            newNode->random = node->random? clones[node->random] : NULL;
            node = node->next;
        }
        return clones[head];
    }
};