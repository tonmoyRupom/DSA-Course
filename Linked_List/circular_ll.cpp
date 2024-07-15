//Circular Linked List

#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node Node;
struct node{
    int data;
    Node *next;
};

void linked_list_traversal(Node *head)
{
    Node *ptr=head;
    //int i=10;
    while(ptr->next!=head)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
}

Node *insert_at_first(Node *head,int x)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=x;
    ptr->next=head;
    Node *p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    head=ptr;
    return head;
}

Node *insert_at_index(Node *head,int index,int x)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=x;
    Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

Node *insert_at_end(Node *head,int x)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=x;
    Node *p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}

Node *deletion_at_first(Node *head)
{
    Node *p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=head->next;
    free(head);
    head=p->next;
    return head;
}

Node *deletion_at_index(Node *head,int index)
{
    int i=0;
    Node *p=head;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    Node *q=p->next;
    p->next=p->next->next;
    free(q);
    return head;
}

Node *deletion_at_end(Node *head)
{
    Node *p=head;
    while(p->next->next!=head)
    {
        p=p->next;
    }
    Node *q=p->next;
    p->next=head;
    free(q);
    return head;
}


int main()
{
    Node *head=(Node*)malloc(sizeof(Node));
    Node *second=(Node*)malloc(sizeof(Node));
    Node *third=(Node*)malloc(sizeof(Node));
    Node *fourth=(Node*)malloc(sizeof(Node));

    head->data=4;
    head->next=second;

    second->data=3;
    second->next=third;
    
    third->data=6;
    third->next=fourth;

    fourth->data=1;
    fourth->next=head;

    linked_list_traversal(head);

    head=insert_at_first(head,5);
    cout<<"After inserting at first: ";
    linked_list_traversal(head);

    head=insert_at_index(head,3,7);
    cout<<"After inserting at index: ";
    linked_list_traversal(head);

    head=insert_at_end(head,13);
    cout<<"After inserting at End: ";
    linked_list_traversal(head);

    head=deletion_at_first(head);
    cout<<"After deletion at first: ";
    linked_list_traversal(head);
    
    head=deletion_at_index(head,2);
    cout<<"After deletion at index: ";
    linked_list_traversal(head);

    head=deletion_at_end(head);
    cout<<"After deletion at End: ";
    linked_list_traversal(head);

  return 0;
}