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
        
        int count = 0;
        if(root->val >= highest){
            count++;
            highest = max(root->val, highest);
        }
        
        count += goodNodesHelper(root->left, highest);
        count += goodNodesHelper(root->right, highest);

        return count;
    }
    int goodNodes(TreeNode* root) {
    
        return goodNodesHelper(root, INT_MIN);
    }
};