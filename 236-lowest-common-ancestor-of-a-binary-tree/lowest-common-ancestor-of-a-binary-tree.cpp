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

    // vector<TreeNode*>findPath(TreeNode* root)
    // {

    // }

    // bool search(TreeNode* root, TreeNode* target)
    // {
    //     if(root == nullptr){
    //         return false;
    //     }
    //     if(root == target)
    //         return true;
    //     return search(root->left, target) || search(root->right, target);
    // }
    // TreeNode* findNode(TreeNode* root, TreeNode* p, TreeNode* q)
    // {

    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // store path to node1
        // store path to node2
        // find common on both paths
        // O(n) time -> 2 traversals, O(n) space

        // search in left, if both in left, return the one occuring first
        // search in right, if both in right, return the one occuring first
        // else return root

        //bool left = search(root->left, p) && search(root->left, q);
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
};