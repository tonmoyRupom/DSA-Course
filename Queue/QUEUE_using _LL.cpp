#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node Node;
struct node{
    int data;
    struct node *next;
};

Node *head=NULL;
Node *tail=NULL;

void enque(int val)
{
    Node *ptr=new Node;
    if(ptr==NULL){cout<<"Queue is Full"<<endl;}
    else
    {
        ptr->data=val;
        ptr->next=NULL;
        if(head==NULL){head=tail=ptr;}
        else
        {
            tail->next=ptr;
            tail=ptr;
        }
    }
}

void traversal()
{
    Node *p=head;
    int number=0;
    while(p!=NULL)
    {
        cout<<"Element "<<number<<" : "<<p->data<<endl;
        p=p->next;
        number++;
    }
}

int Deque()
{
    if(head==NULL){cout<<"Empty Queue"<<endl;return -1;}
    else
    {
        Node *p=head;
        head=head->next;
        int a=p->data;
        free(p);
        return a;
    }
}

int main()
{
    
  enque(10);
  enque(20);
  enque(30);
  traversal();

  cout<<"Dequed element: "<<Deque()<<endl;

  traversal();
  return 0;
}