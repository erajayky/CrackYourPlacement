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
    vector<int> rightSideView(TreeNode* root) {
        int h = height(root);
        vector<int> ans(h);
        bfs(root, ans);
        return ans;
    }

    int height(TreeNode* root){
        if(!root) return 0;

        int l = height(root->left);
        int r = height(root->right);

        return max(l,r) + 1;
    }

    void bfs(TreeNode* r, vector<int> &ans){
        if(!r) return;
        int l = 0;
        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode*curr = q.front();
                q.pop();
                ans[l] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            l++;
        }
    }
};/**
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
    vector<int> rightSideView(TreeNode* root) {
        int h = height(root);
        vector<int> ans(h);
        bfs(root, ans);
        return ans;
    }

    int height(TreeNode* root){
        if(!root) return 0;

        int l = height(root->left);
        int r = height(root->right);

        return max(l,r) + 1;
    }

    void bfs(TreeNode* r, vector<int> &ans){
        if(!r) return;
        int l = 0;
        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode*curr = q.front();
                q.pop();
                ans[l] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            l++;
        }
    }
};