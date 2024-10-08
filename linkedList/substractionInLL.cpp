class Solution {
public:
    
    LinkedList obj = LinkedList();
    // LinkedList is class which helps to create new LL and append nodes at end, just using insert() function
    // see driver code for same
    
    //  function to find lenth of LL
    int length(Node* head)
    {
        int len = 0;
        while(head!=NULL) 
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    // function to reverse LL
    Node* rev(Node* head)
    {
        if(head==NULL) return 0;
        Node* left=NULL;
        Node* right=NULL;
        while(head)
        {
            right=head->next;
            head->next = left;
            left = head;
            head=right;
        }
        return left;
    }
    
    // function to do subtraction
    // here head1 number >= head2 number  -- always
    Node* sub(Node* head1,Node* head2)  
    {
        if(head1==NULL && head2==NULL)
        {
            obj.insert(0);
            return obj.head;
        }
        if(head1==NULL || head2==NULL) 
        {
            Node* ans = rev(head1);
            while(ans && ans->data==0) ans=ans->next;
            return ans;
        }
        bool c= false;
        while(head2)
        {
            if(c) head1->data -=1;
            if(head1->data < head2->data)
            {
                c=true;
                head1->data +=10;
            }
            else c=false;
            int ans = head1->data - head2->data;
            obj.insert(ans);
            head1=head1->next;
            head2= head2->next;
        }
        while(head1)
        {
            if(c) head1->data -=1;
            if(head1->data <0)
            {
                c=true;
                head1->data +=10;
            }
            else c=false;
            int ans = head1->data;
            obj.insert(ans);
            head1=head1->next;
        }
        Node* ans = rev(obj.head);
        while(ans && ans->data==0) ans=ans->next;
        return ans;
    }
    
    
    Node* subLinkedList(Node* head1, Node* head2) 
    {
        while(head1 && head1->data==0) head1=head1->next;
        while(head2 && head2->data==0) head2=head2->next;

    
        // finding length of each number        
        int l1 = length(head1);  
        int l2 = length(head2);
        
        bool flag=true;   // to decide which linked list number id greater
                          // if flag is true then LL1 is greater than LL2 else LL2 is greater than LL1
        
        if(l1>l2) flag=true;
        else if(l1==l2)
        {
            Node* t1 = head1;
            Node* t2 = head2;
            while( t1 && t2 && t1->data==t2->data) 
            {
                t1=t1->next;
                t2=t2->next;
            }
            if(t1 && t2) flag = (t1->data >= t2->data);
        }
        else flag = false;
        
        // reversing the LL to start subtraction from end
        head1 = rev(head1);
        head2 = rev(head2);
        
        Node* ans = NULL;
        
        if(flag)  // if LL1 is greater than LL2
        {
           ans = sub(head1,head2);
        }
        else  // if LL2 is greater than LL1
        {
           ans = sub(head2,head1);
        } 
        
        if(ans == NULL) // if ans is NULL we need to return 0 as ans
        {
            ans = new Node(0);
        }
        
        return ans;
    }
};