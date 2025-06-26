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

    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lH = height(root->left);
        int rH = height(root->right);

        if(abs(lH - rH) > 1 || lH == -1 || rH == -1)
            return -1;
        else
            return 1 + max(lH, rH);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int lH = height(root->left);

        if(lH == -1)
            return false;
        
        int rH = height(root->right);

        if(rH == -1)
            return false;

        if(abs(lH-rH) > 1)
            return false;
        
        return true;
    }
};