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
    ListNode* merge(ListNode *left,ListNode  *right)
    {
        ListNode *ptr=new ListNode(0);
        ListNode *curr=ptr;
        while(left!=NULL && right!=NULL)
        {
            if(left->val<right->val)
            {
                curr->next=left;
                left=left->next;
            }
            else
            {
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        if(left!=NULL)
        {
            curr->next=left;
        }
        if(right!=NULL)
        {
            curr->next=right;
        }
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *slow=head,*fast=head,*temp=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            temp=slow;
            slow=slow->next;  // mid
            fast=fast->next->next;
        }
         
        temp->next=NULL;
        
        ListNode *left_side=sortList(head);
        ListNode *right_side=sortList(slow);
        
        return merge(left_side,right_side);
    }
};
