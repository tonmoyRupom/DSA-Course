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

void preOrder_traversal(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
    }
}

void postOrder_traversal(Node *root)
{
    if(root!=NULL)
    {
        postOrder_traversal(root->left);
        postOrder_traversal(root->right);
        cout<<root->data<<" ";
    }
}

void inOrder_traversal(Node *root)
{
    if(root!=NULL)
    {
        inOrder_traversal(root->left);
        cout<<root->data<<" ";
        inOrder_traversal(root->right);
    }
}

int main() 
{
    Node *p=createNode(4);  //constrcut the root node
    Node *p1=createNode(1);
    Node *p2=createNode(6);
    Node *p3=createNode(5);
    Node *p4=createNode(2);
    //      4
    //     /  \
    //    1    6
    //   /  \
    //  5    2
    
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    preOrder_traversal(p);
    cout<<endl;
    postOrder_traversal(p);
    cout<<endl;
    inOrder_traversal(p);
    cout<<endl;

  return 0;
}