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

ListNode*f(ListNode*l1,ListNode*l2,int &car)
{
    if(!l1) return NULL;
    ListNode*temp=new ListNode(-1);
    temp->next=f(l1->next,l2->next,car);
    int res=l1->val+l2->val+car;
    temp->val=res%10;
    car=res/10;
    return temp; 
}

int len(ListNode*l)
{
    if(!l) return 0;
    return 1+len(l->next);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int m=len(l1); 
    int n=len(l2);
    int diff=abs(m-n);
    ListNode*temp=new ListNode(-1);
    ListNode*head=temp;
    while(diff--)
    {
        temp->next=new ListNode(0);
        temp=temp->next;
    }

    if(m<n) 
    {
        temp->next=l1;
        l1=head->next;
    }
    else 
    {
        temp->next=l2;
        l2=head->next;
    }
    int car=0;
    ListNode*res=f(l1,l2,car);
    if(car) 
    {
        ListNode*ans=new ListNode(1);
        ans->next=res;
        return ans;
    }
    return res;
}
};