/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*>clones;
    Node* cloneGraph(Node* node) {
        
        Node* newNode = NULL;
        if(node == nullptr)
        {
            return newNode;
        }
        if(clones.find(node)!=clones.end())
        {
            return clones[node];
        }
        else{
            newNode = new Node(node->val);
            clones[node] = newNode;
        }
        for(Node* n1 : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(n1));
        }
        return newNode;
    }
};