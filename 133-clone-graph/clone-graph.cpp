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
    Node* DFS(Node* node, unordered_map<Node*, Node*>& cloned)
    {   
        //Node* newNode = new Node(node);
        cloned[node] = new Node(node->val);

        for(Node* curr : node->neighbors)
        {
            if(cloned.find(curr) == cloned.end())
            {
                cloned[curr]= DFS(curr, cloned);
            }
            cloned[node]->neighbors.push_back(cloned[curr]);
        }
        return cloned[node];
    }   
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return NULL;
        
        unordered_map<Node*, Node*> cloned;
        return DFS(node, cloned);
    }
};