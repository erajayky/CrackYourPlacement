void countNodes(Node *node, int &count) {
    if(!node) return;
    countNodes(node->left,count);
    count++;
    countNodes(node->right, count); 
}

void mainLogicFunction(Node* node, Node* &curr, Node* &prev, int &counter, int k, int &f){
    if(!node) return;
    mainLogicFunction(node->left, curr, prev, counter, k, f);
    if(prev==NULL){
        prev = node;
        counter++;
    }
    else if(counter==k){
        counter++;
        curr = node;
        f = 1; 
        return;
    }
    else if(f==0){
        counter++;
        prev = node; 
    }
    mainLogicFunction(node->right, curr, prev, counter, k, f);
}

float findMedian(struct Node *root)
{
      int n = 0; 
      countNodes(root, n);
      
      Node* curr = NULL;
      Node* prev = NULL;
      
      int counter = 1;
      int k = (n/2) + 1;
      int f = 0;
      
      mainLogicFunction(root, curr, prev, counter, k, f);
      if(n&1){
          float ans = (curr->data)*1.0;
          return ans;
      }
      else {
          float ans = ((curr->data+prev->data)*1.0)/(2*1.0);
          return ans;
      }
      
}