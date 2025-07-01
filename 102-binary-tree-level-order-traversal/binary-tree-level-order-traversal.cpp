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
        
        vector<vector<int>>output;

        if(root == NULL)
            return output;

        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size1 = q.size();
            vector<int>v1(size1,0);

            for(int i = 0; i < size1 ; i++)
            {
                TreeNode* node = q.front(); q.pop();

                int val1 = node->val;
                v1[i] = val1;

                if(node->left!= NULL)
                    q.push(node->left);

                if(node->right!= NULL)
                    q.push(node->right);
            }
            output.push_back(v1);
        }
        return output;
    }
};