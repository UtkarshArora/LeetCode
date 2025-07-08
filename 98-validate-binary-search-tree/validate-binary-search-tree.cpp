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

    bool isValidBST(TreeNode* root, long long int minVal, long long int maxVal)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= minVal || root->val >= maxVal)
            return false;
        
        bool ans1 = isValidBST(root->left, minVal, root->val);
        bool ans2 = isValidBST(root->right, root->val, maxVal);

        return ans1 && ans2;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};