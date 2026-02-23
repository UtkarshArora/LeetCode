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
        return 1+max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
       //return max(lh, rh) for all nodes for the tree
        if(root == NULL)
            return 0;
        int maxL = diameterOfBinaryTree(root->left);
        int ht = height(root->left) + height(root->right);
        int maxR = diameterOfBinaryTree(root->right);
        return max(ht, max(maxL,maxR));
    }
};