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

    TreeNode* buildTreeHelper(vector<int>& pre, vector<int>& ino, int preL, int preR, int inL, int inR)
    {   
        if(inL > inR || preL > preR)
            return NULL;

        int node = pre[preL];
        // cout<<"node: "<<node<<endl;
        TreeNode* root = new TreeNode(node);
        for(int i = inL; i <= inR ; i++)
        {
            if(ino[i] == node)
            {
                root->left = buildTreeHelper(pre, ino, preL+1, (preL+i-inL), inL, i-1);
                root->right = buildTreeHelper(pre, ino, (preL+i-inL+1), preR, i+1, inR);
                return root;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};