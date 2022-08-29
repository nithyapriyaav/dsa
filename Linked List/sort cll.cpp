#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
//Represents the node of the list.  
  
struct node{  
    int data;  
    struct node *next;  
};  
  
//Declaring head and tail pointer as null.  
struct node *head = NULL;  
struct node *tail = NULL;  
  
//This function will add the new node at the end of the list.  
void add(int data){  
    //Create new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    //Checks if the list is empty.  
    if(head == NULL){  
        //If list is empty, both head and tail would point to new node.  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }else {  
        //tail will point to new node.  
tail->next = newNode;  
//New node will become new tail.  
tail = newNode;  
//Since, it is circular linked list tail will point to head.  
tail->next = head;  
}  
}  
  
//This function sorts the list in ascending order  
void sortList() {  
    struct node *curr=head,*ptr;
    while(curr->next!=head)
    {
        ptr=curr->next;
        while(ptr!=head)
        {
            if(ptr->data<curr->data)
            {
                int temp=curr->data;
                curr->data=ptr->data;
                ptr->data=temp;
            }
            ptr=ptr->next;
        }
        curr=curr->next;
    }
}  
//This function will display the nodes of circular linked list  
void display(){  
    struct node *current = head;  
    if(head == NULL){  
        printf("List is empty");  
    }  
    else{  
do{  
     //Prints each node by incrementing pointer.  
printf("%d ", current->data);  
current = current->next;  
}while(current != head);  
printf("\n");  
    }  
}  
      
int main()  
{  
   //Adds data to the list  
   add(70);  
   add(90);  
   add(20);  
   add(100);  
   add(50);  
   //Displaying original list  
   printf("Original list: \n");  
   display();  
   //Sorting list  
   sortList();  
   //Displaying sorted list  
   printf("Sorted list: \n");  
   display();  
     
   return 0;  
}  
