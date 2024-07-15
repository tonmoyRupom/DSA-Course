#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct Node node;

struct Node
{
    int key;
    node *left;
    node *right;
    int height;
};

int getHeight(node *n)
{
    if(n==NULL){return 0;}
    return n->height;
}

node *createnode(int key)
{
    node *ptr=new node();
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->key=key;
    ptr->height=1;

    return ptr;
}

int getBlanceFactor(node *n)
{
    if(n==NULL){return 0;}
    return getHeight(n->left)-getHeight(n->right);
}

node *rightRotate(node *y)
{
    node *x=y->left;
    node *T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left));
    x->height=max(getHeight(x->right),getHeight(x->left));
    
    return x;
}

node *leftRotate(node *x)
{
    node *y=x->right;
    node *T2=y->left;

    y->left=x;
    x->right=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    
    return y;
}

node *insert(node *root,int key)
{
    if(root==NULL){return createnode(key);}
    
    if(key<root->key){root->left=insert(root->left,key);}
    else{root->right=insert(root->right,key);}

    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int bf=getBlanceFactor(root);


    //Left-Left Case
    if(bf>1 && key<root->left->key)
    {
        return rightRotate(root);
    }

    //Right-Right Case
    if(bf<-1 && key>root->right->key)
    {
        return leftRotate(root);
    }

    //Left-Right Case

     if(bf>1 && key>root->left->key)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    //Right-Left Case

    if(bf<-1 && key<root->right->key)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder_traversal(node *root)
{
    if(root!=NULL)
    {
        inOrder_traversal(root->left);
        cout<<root->key<<" "<<root->height<<endl;
        inOrder_traversal(root->right);
        
    }
}

int main()
{
    node *root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);

    inOrder_traversal(root);
  return 0;
}