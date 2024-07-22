class Solution {
public:
    bool hasPathSum(TreeNode* root, int t) {
        if(!root) return false;
        t-= root->val;
        if(!root->left && !root->right){
            if(t != 0) return false;
            return true;
        }

        return hasPathSum(root->left, t) || hasPathSum(root->right, t);
        
    }
};