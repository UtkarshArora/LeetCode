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
    
    int finalAns = 0;
    void findPaths(TreeNode* root, vector<int>countNum, int count1)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            int num = root->val;
            countNum[num] = countNum[num] + 1;
            count1 = count1 + (countNum[num]%2 == 1) - (countNum[num]%2 == 0);
            if(count1 <= 1)
                finalAns+=1;
            return;
        }
        int num = root->val;
        countNum[num]+=1;
        count1 = count1 + (countNum[num]%2 == 1) - (countNum[num]%2 == 0);
        findPaths(root->left, countNum, count1);
        findPaths(root->right, countNum, count1);
    }
    int pseudoPalindromicPaths (TreeNode* root) {

        if(root == NULL)
            return 0;
        
        vector<int>countNum(10,0);
        int num = root->val;
        countNum[num]++;
        int count1 = 1;
        if(!root->left && !root->right)
            return count1;
        findPaths(root->right, countNum, count1);
        findPaths(root->left, countNum, count1);
        return finalAns;
    }   
};