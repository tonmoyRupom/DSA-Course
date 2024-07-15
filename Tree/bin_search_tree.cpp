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

/*int isBST(Node *root)
{
    static Node *prev=NULL;
    if(root!=NULL)
    {
        if(isBST(root->left)==NULL){return 0;}
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
}*/

bool isBST(Node *root,Node *min,Node *max)
{
    if(root==NULL){return true;}

    if(min!=NULL && root->data<=min->data){return false;}

    if(max!=NULL && root->data>=max->data){return false;}

    bool leftvalid=isBST(root->left,min,root);
    bool rightvalid=isBST(root->right,root,max);

    return leftvalid and rightvalid;
}

int main() 
{
    Node *p=createNode(5);  //constrcut the root node
    Node *p1=createNode(3);
    Node *p2=createNode(7);
    Node *p3=createNode(1);
    Node *p4=createNode(4);
    Node *p5=createNode(2);
    Node *p6=createNode(8);
    //          5
    //      /       \
    //    3          7
    //   /  \      /   \
    //  1    4    2      8
    
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    inOrder_traversal(p);
    cout<<endl;
    int r=isBST(p,NULL,NULL);
    if(r==1){cout<<"It is a binary search Tree"<<endl;}
    else{cout<<"It is not a binary search Tree"<<endl;}

  return 0;
}