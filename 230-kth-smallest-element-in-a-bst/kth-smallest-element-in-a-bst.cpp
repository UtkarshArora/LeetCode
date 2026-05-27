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

    void inorder(TreeNode* root, int& count, int &ans, int k)
    {
        if(root == NULL)
            return;
        //cout<<"root->val:"<<root->val<<", count:"<<count<<endl;
        inorder(root->left, count, ans, k);
        count+=1;
        //cout<<"count:"<<count<<endl;
        if(count == k)
        {
            ans = root->val;
            return;
        }
        // cout<<"count after increment:"<<count<<endl;
        inorder(root->right, count, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        // main point: during inorder traversal, you are doing inorder traversal only, kth node in that will give you the answer
        
        int count = 0;
        int ans;
        inorder(root, count, ans, k);
        return ans;
    }
};