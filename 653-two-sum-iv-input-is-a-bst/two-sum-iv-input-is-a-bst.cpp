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

    void createVector(TreeNode* root, vector<int>&v)
    {
        if(root == NULL)
            return;
        createVector(root->left, v);
        v.push_back(root->val);
        createVector(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>v1;
        createVector(root, v1); 
        int start = 0, end = v1.size()-1;
        while(start < end)
        {
            int sum = v1[start] + v1[end];
            if(sum == k){
                return true;
            }
            else if(sum > k){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};