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

    int goodNodesHelper(TreeNode* root, int highest)
    {
        if(root == NULL)
            return 0;
        
        int count = (root->val >= highest)? 1 : 0;
        
        count += goodNodesHelper(root->left, max(root->val, highest));
        count += goodNodesHelper(root->right, max(root->val, highest));

        return count;
    }
    int goodNodes(TreeNode* root) {
    
        return goodNodesHelper(root, INT_MIN);
    }
};