Node* util(int n, int pre[], char ln[], int &i){
    if(i >= n) return nullptr;
    
    Node *temp = new Node(pre[i]);
    
    if(ln[i] == 'L'){
        i++;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }
    
    temp->left = util(n, pre, ln, ++i);
    temp->right = util(n, pre, ln, i);
}

Node *constructTree(int n, int pre[], char preLN[])
{
    int i = 0;
    Node *ans = util(n, pre, preLN, i);
    return ans;
}