class Solution {
public:

    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* temp = nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergelist(l1, l2);
    }

    ListNode* mergelist(ListNode*l1, ListNode* l2){
        ListNode*ptr = new ListNode(0);
        ListNode*curr = ptr;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
            if(l1 != NULL){
                curr -> next = l1;
                l1 = l1->next;
            }
        
            if(l2 != NULL){
                curr -> next = l2;
                l2 = l2 ->next;
            }
            return ptr->next;
    }

};