class Solution
{
    public: 
    
    Node* prev = NULL;
    Node* head = NULL;
   
    void converter(Node *root)
    {
        if(root==NULL){
            return;
        } 
        converter(root->left);
        if(prev == NULL) {
            head=root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        converter(root->right);
    }
   
    Node * bToDLL(Node *root){
        converter(root);
        return head;
    }
};