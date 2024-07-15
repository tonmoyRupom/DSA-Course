#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if(ptr->top == 0){return 1;}
    else{return 0;}
}

int isFull(struct Stack *ptr)
{
    if(ptr->top == ptr->size)
    {
        return 1;
    }
    else {return 0;}
}

void push(struct Stack *ptr,int val)
{
    if(isFull(ptr)){cout<<"Stack Overflow.Cant Push"<<endl;}
    else
    {
        ptr->arr[ptr->top]=val;
        ptr->top++;
    }
}

int pop(struct Stack *ptr)
{
    if(isEmpty(ptr))
    {
        cout<<"Stack Underflow.Cant Pop"<<endl;
        return -1;
    }
    else
    {
        int val=ptr->arr[ptr->top-1];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *ptr,int index)
{
    if(ptr->top-index-1<0){cout<<"Not a valid position for the stack";return -1;}
    else
    {
        return ptr->arr[ptr->top-index-1];
    }
}

int stackTop(struct Stack* ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct Stack* ptr)
{
    return ptr->arr[0];
}

int main()
{
    /*struct Stack s;
    s.size=80;
    s.top=-1;
    s.arr=new int[s.size];*/

    struct Stack *s=new struct Stack;  //Allocate memory for the struct

    s->size=5;
    s->top=0;
    s->arr=new int[s->size];

    //Pushing element manually
    /*s->arr[0]=4;
    s->top++;*/

    //Check if stack is empty
    if(isEmpty(s)){cout<<"The stack is empty"<<endl;}
    if(isFull(s)){cout<<"The stack is full"<<endl;}

    push(s,56);
    push(s,13);
    push(s,2);
    push(s,10);
    push(s,12);
    push(s,4);   //Not able to push

    int x=pop(s);
    cout<<"Popped "<<x<<" from the stack"<<endl;
    
    int index=2;
    x=peek(s,index);
    cout<<"Element at index "<<index<<" is:"<<x<<endl;  //From top

    for(int i=0;i<s->top;i++)
    {
        cout<<"The value at index "<<i<<" is "<<peek(s,i)<<endl;   //From top
    }

    cout<<"Bottom of the stack is:"<<stackBottom(s);
  return 0;
}