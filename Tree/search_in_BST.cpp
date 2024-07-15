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

void inOrder_traversal(Node *root)
{
    if(root!=NULL)
    {
        inOrder_traversal(root->left);
        cout<<root->data<<" ";
        inOrder_traversal(root->right);
        
    }
}

int isBST(Node *root)
{
    static Node *prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left)){return 0;}
        if(prev!=NULL && root->data<=prev ->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int Search(Node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return 1;
    }
    else if(root->data>key)
    {
        Search(root->left,key);
    }
    else
    {
        Search(root->right,key);
    }
}

int Search_Iter(Node *root,int key)
{
    while(root!=NULL)
    {
        if(key==root->data){return 1;}
        else if(key<root->data)
        {
            root=root->left;
        }
        else{root=root->right;}
    }
    return NULL;
}

int main() 
{
    Node *p=createNode(50);  //constrcut the root node
    Node *p1=createNode(40);
    Node *p2=createNode(60);
    Node *p3=createNode(20);
    Node *p4=createNode(45);
    Node *p5=createNode(55);
    Node *p6=createNode(70);
    //        50
    //      /    \
    //    40      60
    //   /  \    /   \
    //  20   45  55   70
    
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    inOrder_traversal(p);
    cout<<endl;
    int r=isBST(p);
    if(r==1){cout<<"It is a binary search Tree"<<endl;}
    else{cout<<"It is not a binary search Tree"<<endl;}

    if(Search(p,46)==1){cout<<"Found"<<endl;}
    else{cout<<"Not Found"<<endl;}

    if(Search_Iter(p,45)==1){cout<<"Found"<<endl;}
    else{cout<<"Not Found"<<endl;}

  return 0;
}