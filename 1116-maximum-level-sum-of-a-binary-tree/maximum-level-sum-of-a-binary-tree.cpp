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
    int maxLevelSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        int maxLevel = INT_MAX;
        while(!q.empty())
        {
            int s1 = q.size();
            int sum = 0;
            for(int i = 0 ; i < s1 ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            if(sum > maxSum)
            {
                maxSum = sum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};