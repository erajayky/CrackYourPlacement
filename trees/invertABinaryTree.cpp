class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->left = r;
        root->right = l;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};