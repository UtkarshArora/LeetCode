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

    void inorder(TreeNode* root, int k, vector<int>& traversal)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, k, traversal);
        traversal.push_back(root->val);
        inorder(root->right, k, traversal);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        // main point: during inorder traversal, you are doing inorder traversal only, kth node in that will give you the answer
        
        vector<int>traversal;
        inorder(root, k, traversal);
        return traversal[k-1];
    }
};