class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head, *prev = new ListNode(-1), *ans = prev;
        prev->next = temp;

        while(temp && temp->next){
            if(temp->val == temp->next->val){
                int v = temp->val;
                while(temp && temp->val == v) temp = temp->next;
                prev->next = temp;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        
        return ans->next;
    }
};