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

bool isBST(Node *root,Node *min,Node *max)
{
    if(root==NULL){return true;}

    if(min!=NULL && root->data<=min->data){return false;}

    if(max!=NULL && root->data>=max->data){return false;}

    bool leftvalid=isBST(root->left,min,root);
    bool rightvalid=isBST(root->right,root,max);

    return leftvalid and rightvalid;
}

void insert(Node *root,int key)
{
    Node *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data){return;}
        else if(root->data>key)
        {
            root=root->left;
        }
        else{root=root->right;}
    }
    Node *ptr=createNode(key);   //New Node
    if(key<prev->data){prev->left=ptr;}
    else{prev->right=ptr;}

}

/*Node *inOrderPredecessor(Node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

Node *deletenode(Node *root,int value)
{
    if(root==NULL){return NULL;}
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
      
    //Search for the node to be deleted
        if(value<root->data)
        {
            root->left=deletenode(root->left,value);
        }
        else if(value>root->data)
        {
            root->right=deletenode(root->right,value);
        }
        //Deletion Strategy when node is found
        else
        {
            Node *ipre=inOrderPredecessor(root);
            root->data=ipre->data;
            root->left=deletenode(root->left,ipre->data);
        }
        return root;
}*/

Node *FindMin(Node *root)
{
    while(root->left!=NULL){root=root->left;}
    return root;
}

Node *Delete(Node *root,int value)
{
    if(root==NULL){return root;}
    else if(root->data>value){root->left=Delete(root->left,value);}
    else if(root->data<value){root->right=Delete(root->right,value);}

    //Deletion Strategy when node is found
    else
    {
        //Case-01:No Child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }

        //Case-02:One child
        else if(root->left==NULL)   //Empty left child
        {
            Node *temp=root;
            root=root->right;
            delete temp;
        }

        else if(root->right==NULL)  //Empty right child
        {
            Node *temp=root;
            root=root->left;
            delete temp;
        }

        //Case-03:Two Child
       else
       {
        Node *temp=FindMin(root->right);
        root->data=temp->data;
        root->right=Delete(root->right,temp->data);   //Delete Duplicate
       } 
    } 
    return root;
}

int main() 
{
    Node *p=createNode(8);  //constrcut the root node
    Node *p1=createNode(3);
    Node *p2=createNode(10);
    Node *p3=createNode(1);
    Node *p4=createNode(6);
    Node *p5=createNode(14);
    Node *p6=createNode(4);
    Node *p7=createNode(7);
    Node *p8=createNode(13);
    //          8
    //      /        \
    //    3          10
    //   /  \       /   \
    //  1   6           14
    //     / \          /
    //    4   7         13
    //                 /
    //                12 
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;
    p4->left=p6;
    p4->right=p7;
    p5->left=p8;
    inOrder_traversal(p);
    cout<<endl;
    int r=isBST(p,NULL,NULL);
    if(r==true){cout<<"It is a binary search Tree"<<endl;}
    else{cout<<"It is not a binary search Tree"<<endl;}

    insert(p,5);
    inOrder_traversal(p);
    cout<<endl;

    r=isBST(p,NULL,NULL);
    if(r==true){cout<<"It is a binary search Tree"<<endl;}
    else{cout<<"It is not a binary search Tree"<<endl;}

    /*p=Delete(p,3);
    inOrder_traversal(p);*/
    
  return 0;
}