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
            return NULL;
        
        unordered_map<Node*, Node*>cloned;
        queue<Node*>q;
        q.push(node);
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;

        while(!q.empty()){
        
            Node* curr = q.front();
            q.pop();
            for(Node* temp : curr->neighbors)
            {
                if(cloned.find(temp) == cloned.end())
                {
                    Node* newTemp = new Node(temp->val);
                    q.push(temp);
                    cloned[temp] = newTemp;
                }
                cloned[curr]->neighbors.push_back(cloned[temp]);
            }
        }
        return cloned[node];
    }
};