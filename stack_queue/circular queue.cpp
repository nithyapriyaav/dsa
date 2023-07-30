#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 5
int a[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int data)
{
    if((rear+1)%MAX_SIZE==front)
    {
        cout<< "queue is full"<<endl;
    }
    else if(front==-1 && rear==-1)
    {
        rear=(rear+1)%MAX_SIZE;
        front++;
        a[rear]=data;
        cout<<"ele inserted: "<<data<<endl;
    }
    else
    {
        rear=(rear+1)%MAX_SIZE;
        a[rear]=data;
        cout<<"ele inserted: "<<data<<endl;
    }
    cout<<front<<" "<<rear<<endl;
}
void dequeue()
{
    if(front==rear)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        int ele=a[front];
        cout<< "popped ele: "<<ele<<endl;
        front=(front+1)%MAX_SIZE;
    }
}
void peek()
{
    if(front==rear)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        int ele=a[front];
        cout<< "Top ele: "<<ele<<endl;
    }
}
void Print()
{
    int count = ((rear + MAX_SIZE - front) % MAX_SIZE)+1;

int i;

for (i = 0; i < count; i++)

{

printf("%d ", a[(front+i)%MAX_SIZE]);

}

printf("\n");

}
int main()
{
   enqueue(3);
   enqueue(33);
   enqueue(31);
   peek();
   enqueue(35);
   enqueue(32);
   Print();
   dequeue();
   enqueue(30);
   dequeue();
   dequeue();
   dequeue();
   dequeue();
   enqueue(90);
    
}