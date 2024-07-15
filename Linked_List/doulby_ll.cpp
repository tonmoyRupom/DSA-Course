#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node Node;

struct node{
    int data;
    Node *next;
    Node *pre;
};

Node *head=NULL,*tail=NULL;

void insert_at_first(int x)
{
    Node *ptr=new Node;
    ptr->data=x;
    ptr->next=NULL;
    ptr->pre=NULL;
    if(head==NULL)
    {
        head=ptr;
        tail=ptr;
    }
    else
    {
        ptr->next=head;
        head->pre=ptr;
        head=ptr;
    }
}

void insert_at_last(int x)
{
    Node *ptr=new Node;
    ptr->data=x;
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

void insert_at_index(int index,int x)
{
    Node *p=head;
    Node *ptr=new Node;
    ptr->data=x;
    ptr->next=NULL;
    ptr->pre=NULL;
    int i=0;
    while(i<index-1)
    {
        p=p->next;
        i++;
    }
    /*if(index==0 && head==NULL)  //first e add + no element
    {
        head=ptr;
        tail=ptr;
    }
    else if(index==0 && head!=NULL)  //first e add + at least one element
    {
        ptr->next=head;
        head->pre=ptr;
        head=ptr;
    }*/
    if(i==0){insert_at_first(x);}
    else if(p==tail)   //last e add hobe
    {
        /*tail->next=ptr;
        ptr->pre=tail;
        tail=ptr;*/
        insert_at_last(x);
    }
    else    //maje add hobe
    {
        ptr->next=p->next;
        p->next->pre=ptr;
        p->next=ptr;
        ptr->pre=p;
    }
}
void linked_list_traversal(Node *head)
{
    Node *ptr=head;
    //int i=10;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void deletion_at_first()
{
    if(head==NULL){cout<<"Deletion not possible";}
    else
    {
        Node *q=head;
        head=head->next;
        free(q);
    }
}

void deletion_at_last()
{
    if (head == NULL) {
        cout << "Deletion not possible";
    }
     else if (head == tail) 
     {
        // If there is only one element
        free(head);
        head = tail = NULL;
    }
    else
    {
        Node *p=tail;
        tail=tail->pre;
        tail->next=NULL;   //update the pointer to new tail
        free(p);
    }
}

void deletion_at_index(int index)
{
    Node *p=head;
    int i=0;
    while(i!=index-1 && i<index)
    {
        p=p->next;
        i++;
    }
    if(index==0){deletion_at_first();}
    else if(p==tail){deletion_at_last();}
    else
    {
        p->next->next->pre=p;
        p->next=p->next->next;
    }
}
int main()
{
    insert_at_first(5);
    insert_at_first(3);
    insert_at_first(7);
    cout<<"After inserting at first: ";
    linked_list_traversal(head);         //7 3 5
    insert_at_last(13);
    insert_at_last(2);
    cout<<"After inserting at last: ";   //7 3 5 13 2
    linked_list_traversal(head);
    insert_at_index(0,10);
    cout<<"After inserting at index: ";  //7 3 10 5 13 2
    linked_list_traversal(head);

    deletion_at_first();
    cout<<"After deleting first element: ";   //3 10 5 13 2
    linked_list_traversal(head);

    deletion_at_last();
    cout<<"After deleting last element: ";   //3 10 5 13
    linked_list_traversal(head);

    deletion_at_index(0);
    cout<<"After deleting at index:";   //3 10 5
    linked_list_traversal(head);

  return 0;
}