#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node Node;
struct node{
    int data;
    Node *next;
};

Node *top=NULL;

int isEmpty()
{
    if(top==NULL){return 1;}
    else{return 0;}
}

int isFull()
{
    Node *p=new Node;
    if(p==NULL){return 1;}
    else{return 0;}
}

void traversal()
{
    Node *p=top;
    int number=0;
    while(p!=NULL)
    {
        cout<<"Element "<<number<<": "<<p->data<<endl;
        p=p->next;
        number++;
    }
}

void push(int x)   //insert at first
{
    if(isFull()){cout<<"Stack Overflow"<<endl;}
    else
    {
        Node *ptr=new Node;
        ptr->data=x;
        ptr->next=top;
        top=ptr;
    }
}

int pop()
{
    if(isEmpty()){cout<<"Empty Stack.Pop not possible"<<endl;}
    else
    {
        Node *p=top;
        int y=top->data;
        top=top->next;
        free(p);
        return y;
    }
}

int peek(int index)    //upor theke
{
    Node *p=top;
    for(int i=0;i<index && p!=NULL;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        return p->data;
    }
    else{return -1;}
}

int stackTop()
{
    if(top==NULL){return -1;}
    else{return top->data;}
}

int stackBottom()
{

}

int main()
{
  push(13);
  push(10);
  push(56);
  push(17);
  push(2);
  push(4);

  traversal();

  int x=pop();
    cout<<"Element "<<x<<" popped from the list"<<endl;
    x=pop();
    cout<<"Element "<<x<<" popped from the list"<<endl;

   int y=3;
   cout<<"Element at index "<<y<<" is: "<<peek(y)<<endl; 

  return 0;
}