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

    Node* clone(Node* node, unordered_map<Node*,Node*>& map1)
    {
        if(node == NULL)
            return node;
        if(map1.find(node)!=map1.end())
            return map1[node];
        
        Node* newNode = new Node(node->val);
        map1[node] = newNode;
        for(Node* n : node->neighbors)
        {
            if(map1.find(n) == map1.end())
            {
                newNode->neighbors.push_back(clone(n, map1));
            }
            else
                newNode->neighbors.push_back(map1[n]);
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>map1;
        return clone(node, map1);
    }
};