int isPalindrome(int n)
{
   int i=0,j=0;
   Node *front,*rear;
   while(i<n/2)
   {
       front=head,rear=head;
       for(j=0;j<i;j++)
          front=front->next;
       for(j=0;j<n-i-1;j++)
          rear=rear->next;
       if(front->data!=rear->data)
          return 0;
       i++;
   }
   return 1;
}