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

    Node* clone(Node* node, unordered_map<Node*, Node*>& clones)
    {
        Node* newNode = new Node(node->val);
        clones[node] = newNode;
        for(auto ne : node->neighbors)
        {
            if(clones.find(ne)!=clones.end())
            {
                newNode->neighbors.push_back(clones[ne]);
            }
            else
            {
                newNode->neighbors.push_back(clone(ne, clones));
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
        {
            return NULL;
        }
        else if(node->neighbors.size() == 0)
        {
            return new Node(node->val);
        }
        unordered_map<Node*, Node*>clones;
        return clone(node, clones);
    }
};