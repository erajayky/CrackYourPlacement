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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return util(head, n);
    }

    ListNode* util(ListNode* head, int &n){
        if(!head) return NULL;

        auto res = util(head->next, n);
        n--;

        head->next = res; 
        
        if(n == 0) return res;
        return head;
    }

};