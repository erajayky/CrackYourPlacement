class Solution {
public:
    Node* flatten(Node* head) {
    if(head == nullptr) return nullptr;

    Node*current = head;
    stack<Node*> s;

    while(current != nullptr){
        if(current->child != nullptr){
            Node*nextNode = current->next;
            current->next = current->child;
            current->child->prev = current;
            current->child = nullptr;
            if(nextNode != nullptr) s.push(nextNode);
        }else if(current->next == nullptr && !s.empty()){
            Node* nextNode = s.top();
            s.pop();
            current->next = nextNode;
            nextNode->prev = current;
        }
        current = current->next;
    }
    return head;
    }
};