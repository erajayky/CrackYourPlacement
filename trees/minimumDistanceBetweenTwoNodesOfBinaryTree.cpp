class Solution{
    public:
    int findDist(Node* root, int a, int b) {
        Node* l = lca(root, a, b);
        int x = dis(l, a);
        int y = dis(l, b);
        return x+y;
    }
    
    Node* lca(Node*root, int a, int b){
        if(!root || root->data == a || root->data == b) return root;
        Node* l = lca(root->left, a, b);
        Node* r = lca(root->right, a, b);
        if(l && r) return root;
        if(l) return l;
        return r;
    }
    
    int dis(Node* l, int a){
        if(!l) return INT_MIN;
        
        if(l->data == a) return 0;
        int x = dis(l->left, a);
        int y = dis(l->right, a);
        
        return max(x,y)+1;
    }
};