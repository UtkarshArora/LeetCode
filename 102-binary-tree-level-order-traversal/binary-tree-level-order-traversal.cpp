/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int num_nodes = q.size();
            vector<int>v1;
            for(int i = 0; i < num_nodes; i++)
            {
                TreeNode* n1 = q.front();
                v1.push_back(n1->val);
                q.pop();
                if(n1->left)
                    q.push(n1->left);
                if(n1->right)
                    q.push(n1->right);
            }
            ans.push_back(v1);
        }
        return ans;
    }
};