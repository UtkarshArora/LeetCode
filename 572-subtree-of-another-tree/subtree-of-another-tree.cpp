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

    bool checkIdentical(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
            return true;

        if (!root || !subRoot)
            return false;

        return root->val == subRoot->val && checkIdentical(root->left, subRoot->left) && checkIdentical(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (!root && !subRoot)
            return true;

        if (!root || !subRoot)
            return false;

        bool ans = false;
        ans = ans || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  
        if(root->val == subRoot->val)
        {
            ans = ans || checkIdentical(root, subRoot);
        }
        return ans;
    }
};