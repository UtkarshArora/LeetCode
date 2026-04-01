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

    unordered_map<Node*, Node*>map1;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        if(map1.find(node)!=map1.end())
            return map1[node];
        
        Node* newNode = new Node(node->val);
        map1[node] = newNode;
        for(Node* n : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(n));
        }
        return newNode;
    }
};