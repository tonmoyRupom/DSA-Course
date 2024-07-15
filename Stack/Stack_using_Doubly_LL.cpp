#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node Node;
struct node{
    int data;
    Node *next;
    Node *pre;
};

Node *head=NULL;
Node *tail=NULL;

int isEmpty()
{
    if(tail==NULL){return 1;}
    else{return 0;}
}
void push(int data)  //insert at last
{
    Node *ptr=new Node;
    ptr->data=data;
    ptr->next=NULL;
    ptr->pre=NULL;
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
    }
    else
    {
        tail->next=ptr;
        ptr->pre=tail;
        tail=ptr;
    }
}

int pop()    //Delete last node
{
    if(isEmpty())
    {
        cout<<"Empty Stack.Pop not possible"<<endl;
        return -1;
    }
    else if(head==tail)
    {
        int x=tail->data;
        free(tail);
        head=tail=NULL;
        return x;
    }
    else
    {
        Node *p=tail;
        int x=tail->data;
        tail=tail->pre;
        tail->next=NULL;
        free(p);
        return x;
    }
}

void traversal()
{
    Node *p=head;
    int number=0;
    while(p!=NULL)
    {
        cout<<"Element "<<number<<": "<<p->data<<endl;
        p=p->next;
        number++;
    }
}

int peek(int index)  //Nich theke numbering
{
    int i=0;
    Node *p=head;
    if(head==NULL){cout<<"Stack is empty."<<endl;return -1;}
    else
    {
        while(i!=index)
        {
            p=p->next;
            i++;
        }
        return p->data;
    }
}

int main()
{
    if(isEmpty()){cout<<"The stack is empty"<<endl;}
  push(56);
  push(10);
  push(13);
  push(17);
  push(19);
  push(9);

    traversal();

  int y=pop();
  cout<<"Element "<<y<<" popped from the Stack."<<endl;
  y=pop();
  cout<<"Element "<<y<<" popped from the Stack."<<endl;
  y=pop();
  cout<<"Element "<<y<<" popped from the Stack."<<endl;

  //y=0;
  //cout<<"Element "<<y<<" is:"<<peek(y)<<endl;

  return 0;
}