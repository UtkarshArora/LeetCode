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

// class hD{
//     public:
//         int height;
//         int dia;
//     hD(int height, int dia)
//     {
//         this->height = height;
//         this->dia = dia;
//     }
// };
class Solution {
public:

    // int hDia(TreeNode* root)
    // {
    //     if(root == NULL)
    //         return (hD(0,0));
        
    //     hD lhD = hDia(root->left);
    //     hD rhD = hDia(root->right);
    //     int height = 1 + max(lhD.height, rhD.height);
    //     int diam = max(max(lhD.dia, rhD.dia), (lhD.height + rhD.height));
    //     hD ans = hD(height, diam);
    //     return ans;
    // }
    int maxDiam(TreeNode* root, int& maxDia)
    {
        if(root == NULL)
            return 0;
        
        int lh = maxDiam(root->left, maxDia);
        int rh = maxDiam(root->right, maxDia);
        int dia = lh + rh ;
        // int dia = max((lh.height+rh.height), max(lh.dia, rh.dia));
        maxDia = max(dia, maxDia);
        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        maxDiam(root, maxDia);
        return maxDia;
    }
};