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
        
        queue<Node*>q;
        if(node == NULL)
            return node;
        q.push(node);
        Node* mainNode = NULL;
        unordered_map<Node*, Node*>nodeMappings;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            Node* node1 = NULL;
            if(nodeMappings.find(temp)!=nodeMappings.end())
                node1 = nodeMappings[temp];
            else{
                node1 = new Node(temp->val);
                nodeMappings[temp] = node1;
            }

            if(mainNode == NULL)
                mainNode = node1;
            
            for(auto n : temp->neighbors)
            {
                if(!nodeMappings[n]){
                    q.push(n);
                    nodeMappings[n] = new Node(n->val);
                }
                node1->neighbors.push_back(nodeMappings[n]);
            }
        }
        return mainNode;
    }
};