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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1=list1, *t2=list2, *ans= new ListNode(-1), *res=ans;

        while(t1 && t2){
            if(t1->val < t2->val){
                ans->next=t1;
                t1=t1->next;
            }else{
                ans->next=t2;
                t2=t2->next;
            }
            ans = ans->next;
        }

        if(t1) ans->next = t1;
        if(t2) ans->next = t2;

        return res->next;
    }
};