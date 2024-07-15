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

//Case 01
Node *insertAtFirst(Node *head,int data)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return head;
}

//Case 02
Node *insertAtIndex(Node *head,int data,int index)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;         //jei index e add korte hobe
        i++;                     //tar ag porjonto p pointer ke niye ashchi       
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return head;
}

//Case 03
Node *insertAtEnd(Node *head,int data)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    Node *p=head;
    while(p->next!=NULL)    //p->next must be careful
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
}

//Case 04
Node *insertAfterNode(Node *head,Node *preNode,int data)
{
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=preNode->next;
    preNode->next=ptr;

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
    linkedlistTraversal(head);

    //Node *head=NULL;

    head=insertAtFirst(head,56);
    printf("After insertion at first\n");
    linkedlistTraversal(head);

    head=insertAtIndex(head,67,4);
    printf("After insertion at Index\n");
    linkedlistTraversal(head);

    /*head=insertAtEnd(head,37);
    printf("After insert at the end\n");
    linkedlistTraversal(head);

    head=insertAfterNode(head,third,77);
    printf("After insert after the node\n");
    linkedlistTraversal(head);*/
    
    return 0;
}