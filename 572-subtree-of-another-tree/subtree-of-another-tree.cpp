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
    bool isSameTree(TreeNode* root, TreeNode* root1) {
        if (root == NULL && root1 == NULL)
            return true;

        if (root == NULL || root1 == NULL)
            return false;

        return (root->val == root1->val) &&
               isSameTree(root->left, root1->left) &&
               isSameTree(root->right, root1->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL && subRoot == NULL)
            return true;
        
        if(root == NULL)
            return false;
        
        bool ans1 = false;
        if(root->val == subRoot->val){
            ans1 = isSameTree(root, subRoot);
            if(ans1)
                return true;
        }
        bool ans2 = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
        return ans2;
    }
};