class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }

       return isBalancedHelper(root)!=-1;
    }

    int isBalancedHelper(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftHeight = isBalancedHelper(root->left);
        int rightHeight = isBalancedHelper(root->right);

        if(leftHeight ==-1 || rightHeight == -1)
        {
            return -1;
        }

        if(abs(leftHeight-rightHeight)>1)
        {
            return -1;
        }

        return max(leftHeight, rightHeight)+1;

    }
};