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
class BSTIterator {
public:
    vector<int>inOrderT;
    int len, index;
    void inOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inOrder(root->left);
        inOrderT.push_back(root->val);
        inOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inOrder(root);
        len = inOrderT.size();
        index = -1;
    }
    
    int next() {
        index = index+1;
        return inOrderT[index];
    }
    
    bool hasNext() {
        return (index+1)!=len;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */