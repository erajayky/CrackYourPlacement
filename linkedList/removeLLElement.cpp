class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*temp = new ListNode(-1);
        temp->next = head;
        ListNode*ans = temp;

        while(temp && temp->next){
            if(temp->next->val == val){
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }

        return ans->next;
    }
};