/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL)
            return NULL;
        if (!p && q)
            return q;
        else if (p && !q)
            return p;

        int rootVal = root->val;
        if (p->val <= rootVal && q->val >= rootVal) {
            return root;
        } else if (p->val >= rootVal && q->val <= rootVal) {
            return root;
        } else if (p->val < rootVal && q->val < rootVal) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > rootVal && q->val > rootVal) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};