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
    Node* cloneGraph(Node* node) {

        if(!node)
            return node;
        unordered_map<Node*, Node*>clones;
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            Node* node1 = q.front();
            q.pop();
            Node* newNode = NULL;
            if(!clones.count(node1)){
                newNode = new Node(node1->val);
                clones[node1] = newNode;
            }
            newNode = clones[node1];
            for(auto node : node1->neighbors)
            {
                if(!clones.count(node)){
                    clones[node] = new Node(node->val);
                    q.push(node);
                }
                newNode->neighbors.push_back(clones[node]);
            }
        }
        return clones[node];
    }
};