/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode*temp = head;
        int n=1, ans = 0;

        while(temp->next != nullptr){
            n++;
            temp = temp->next;
        }

        temp = head;
        n--;
        
        while(temp != nullptr){
            ans += (temp->val * pow(2, n--));
            temp = temp->next;
        }      

        return ans;
    }
};