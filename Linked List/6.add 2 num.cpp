  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *ptr=head;
        int carry=0,sum=0,x,y;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1==NULL)
                x=0;
            else
            {
                x=l1->val;
                l1=l1->next;
            }
            if(l2==NULL)
                y=0;
            else
            {
                y=l2->val;
                l2=l2->next;
            }
            sum=x+y+carry;
            carry=sum/10;
            int ele=sum%10;
            ptr->next=new ListNode(ele);
            ptr=ptr->next;
        }
        if(carry!=0)
        {
            ptr->next=new ListNode(carry);
            ptr=ptr->next;
        }
        return head->next;
}