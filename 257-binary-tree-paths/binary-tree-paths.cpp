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


    void DFS(TreeNode* root, string path, vector<string>&res)
    {
        if(root == NULL)
            return;
        if(path.empty())
        {
            path = to_string(root->val);
        }
        else
        {
            path = path + "->" + to_string(root->val);
        }
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(path);
            return;
        }
        DFS(root->left, path, res);
        DFS(root->right, path, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       
       vector<string>res;
       string path = "";
       DFS(root, path, res);
       return res;
    }

};