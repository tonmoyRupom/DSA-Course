#include<bits/stdc++.h>
#define ll long long
typedef struct node Node;
using namespace std;
struct node{
    int data;
    Node *left;
    Node *right;
};
struct node *createNode(int data)
{
    Node *n=new Node();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int main()
{
    /*//Constcuting the root node
    Node *p=new Node();
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    //Constcuting the second node
    Node *p1=new Node();
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;

    //Constcuting the third node
    Node *p2=new Node();
    p2->data=4;
    p2->left=NULL;
    p2->right=NULL;

    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;*/

    Node *p=createNode(2);  //constrcut the root node
    Node *p1=createNode(1);
    Node *p2=createNode(4);

    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
  return 0;
}