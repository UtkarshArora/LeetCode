/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int preStart, int preEnd, int inStart, int inEnd) {
         
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        int val = preorder[preStart];
        int index = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == val) {
                index = i-1; //index = leftInOrderEnd
                break;
            }
        }
        int count = (index - inStart) + 1;
        int leftPreStart = preStart + 1;
        int leftPreEnd = leftPreStart + count - 1;
        int rightPreStart = leftPreEnd + 1;
        int rightPreEnd = preEnd;
        int leftInStart = inStart;
        int leftInEnd = index;
        int rightInStart = leftInEnd + 2;
        int rightInEnd = inEnd;

        TreeNode* root = new TreeNode(val);

        root->left = buildTree(preorder, inorder, leftPreStart, leftPreEnd,
                               leftInStart, leftInEnd);

        root->right = buildTree(preorder, inorder, rightPreStart, rightPreEnd,
                                rightInStart, rightInEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return buildTree(preorder, inorder, 0, (preorder.size() - 1), 0,
                         (inorder.size() - 1));
    }
};