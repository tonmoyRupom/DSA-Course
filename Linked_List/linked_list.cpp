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

int main()
{
    //Allocate memory for nodes in the linked list in Heap
    Node *head=(Node*)malloc(sizeof(Node));
    Node *second=(Node*)malloc(sizeof(Node));
    Node *third=(Node*)malloc(sizeof(Node));
    head->data=7;
    head->next=second;
    second->data=10;
    second->next=third;
    //Terminate the linked list
    third->data=13;
    third->next=NULL;
    linkedlistTraversal(head);

    return 0;
}