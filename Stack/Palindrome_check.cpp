#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Stack{
    int size;
    int top;
    char *arr;
};

Stack *initStack(string s)
{
    struct Stack *st=new struct Stack;
    st->top=-1;
    st->size=s.size()/2;
    st->arr=new char[st->size];
    return st;
}

int isEmptyStack(struct Stack *ptr)
{
    if(ptr->top == -1){return 1;}
    else{return 0;}
}

int isFullStack(struct Stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else {return 0;}
}

void push(struct Stack *ptr,char val)
{
    if(isFullStack(ptr)){cout<<"Stack Overflow.Cant Push"<<endl;}
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(struct Stack *ptr)
{
    if(isEmptyStack(ptr))
    {
        cout<<"Stack Underflow.Cant Pop"<<endl;
        return -1;
    }
    else
    {
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

struct Queue{
    int size;
    int fi;
    int bi;
    char *arr;
};

Queue *initQueue(string s)
{
    struct Queue *q=new struct Queue;
    q->size=s.size()/2;
    q->fi=-1;   //track forward index
    q->bi=-1;   //track backward index
    q->arr=new char[q->size];
    return q;
}

int isFullQueue(struct Queue *q)
{
    if(q->fi==q->size-1){return 1;}
    else{return 0;}
}

int isEmptyQueue(struct Queue *q)
{
    if(q->fi==q->bi){return 1;}
    else{return 0;}
}

void enque(struct Queue *q,char data)
{
    if(isFullQueue(q)==1){cout<<"Queue is Full"<<endl;}
    else
    {
        q->fi++;
        q->arr[q->fi]=data;
    }
}

char Deque(struct Queue *q)
{
    char a;
    if(isEmptyQueue(q))
    {
        cout<<"Queue is Empty"<<endl;
        q->fi=-1;
        q->bi=-1;
        return -1;
    }
    else
    {
        q->bi++;
        a=q->arr[q->bi];
        return a;
    }
}

void palindrome(Stack *st,Queue *q,string s)
{
    for(int i=0;i<s.size()/2;i++)
    {
        push(st,s[i]);
    }
    if(s.size()%2==0)
    {
        for(int i=s.size()/2;i<s.size();i++)
        {
            enque(q,s[i]);
        }
    }
    else
    {
       for(int i=(s.size()/2)+1;i<s.size();i++)
        {
            enque(q,s[i]);
        } 
    }
    bool flag=1;
    while(isEmptyStack(st)!=1)
    {
        if(pop(st)!=Deque(q))
        {
            cout<<"Not Palindrome"<<endl;
            flag=0;
            break;
        }
    }
    if(flag==1){cout<<"Palindrome"<<endl;}
}
int main()
{
    string s;
    cin>>s;
    initStack(s);
    Stack *st=initStack(s);
    Queue *q=initQueue(s);
    palindrome(st,q,s);
  return 0;
}