/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    //(3,3) => (4,3) => (1,3) => 

    bool isSubTreeHelper(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
            return true;

        if (!root && subRoot || root && !subRoot)
            return false;
        
        if(root->val!=subRoot->val)
            return false;

        return isSubTreeHelper(root->left, subRoot->left) && isSubTreeHelper(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (!root && !subRoot)
            return true;

        if (!root && subRoot || root && !subRoot)
            return false;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        if (left || right){
            return true;
        }
        if (root->val == subRoot->val) {
            return isSubTreeHelper(root->left, subRoot->left) &&
                   isSubTreeHelper(root->right, subRoot->right);
        }
        return false;
    }
};