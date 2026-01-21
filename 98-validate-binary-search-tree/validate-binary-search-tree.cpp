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

    bool isValidBST(TreeNode* root, double minVal, double maxVal)
    {
        if(root == NULL)
            return true;
        
        if(root->val > minVal && root->val < maxVal)
            return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        double minD = std::numeric_limits<double>::lowest();
        double maxD = std::numeric_limits<double>::max();
        bool ans1 = isValidBST(root->left, minD, root->val);
        bool ans2 = isValidBST(root->right, root->val, maxD);
        bool ans = ans1 && ans2;
        if(root && root->left)
            ans = ans & root->val > root->left->val;
        if(root && root->right)
            ans = ans & root->val < root->right->val;
        return ans;
    }
};