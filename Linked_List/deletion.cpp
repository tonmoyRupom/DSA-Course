#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node{
    int data;
    Node *next;
};

void linkedlistTraversal(Node *ptr)
{
    int number=0;
     while(ptr!=NULL)
     {
        number++;
        printf("Element %d: %d\n",number,ptr->data);
        ptr=ptr->next;
     }
}

//Case-01
Node *deletionAtFirst(Node *head)
{
    Node *p=head;
    head=head->next;
    free(p);
    return head;
}

//Case-02
Node *deletionAtIndex(Node *head,int index)
{
    Node *p=head;
    Node *q=head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head; 
}

//Case-03
Node *deletionAtEnd(Node *head)
{
    Node *p=head;
    Node *q=head->next;
    while(q->next!=NULL)   //must be careful
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

//Case-04
Node *deletionAtValue(Node *head,int value)
{
    Node *p=head;
    Node *q=head->next;
    int i=0;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data!=value){printf("Given data was not in the linked list!!!!!\n");}
    else
    {
        p->next=q->next;
        free(q);
    }
    return head; 
}

int main()
{
    //Allocate memory for nodes in the linked list in Heap
    Node *head=(Node*)malloc(sizeof(Node));
    Node *second=(Node*)malloc(sizeof(Node));
    Node *third=(Node*)malloc(sizeof(Node));
    Node *fourth=(Node*)malloc(sizeof(Node));
    head->data=7;
    head->next=second;
    second->data=10;
    second->next=third;
    third->data=13;
    third->next=fourth;
    //Terminate the linked list
    fourth->data=2;
    fourth->next=NULL;

    printf("Before delation\n");
    linkedlistTraversal(head);

    head=deletionAtFirst(head);
    printf("After deleting first element\n");
    linkedlistTraversal(head);

    /*head=deletionAtIndex(head,1);
    printf("After deletion at index\n");
    linkedlistTraversal(head);*/

    /*head=deletionAtEnd(head);
    printf("After deletion at the end\n");
    linkedlistTraversal(head);*/

    /*printf("After deleting the given value\n");
    head=deletionAtValue(head,100);
    linkedlistTraversal(head);*/

    return 0;
}