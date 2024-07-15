#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Queue{
    int size;
    int fi;
    int bi;
    int *arr;
};

void initQueue(struct Queue *q,int size)
{
    q->size=size;
    q->fi=-1;   //track forward index
    q->bi=-1;   //track backward index
    q->arr=new int[q->size];
}

int isFull(struct Queue *q)
{
    if(q->fi==q->size-1){return 1;}
    else{return 0;}
}

int isEmpty(struct Queue *q)
{
    if(q->fi==q->bi){return 1;}
    else{return 0;}
}

void enque(struct Queue *q,int data)
{
    if(isFull(q)==1){cout<<"Queue is Full"<<endl;}
    else
    {
        q->fi++;
        q->arr[q->fi]=data;
    }
}

int Deque(struct Queue *q)
{
    int a;
    if(isEmpty(q))
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

void print(struct Queue *q)
{
    int number=0;
    for(int i=q->bi+1;i<=q->fi;i++)
    {
        cout<<"Element "<<number<<" is: "<<q->arr[i]<<endl;
        number++;
    }
}

int main()
{
  struct Queue *q=new struct Queue;
  initQueue(q,10);
  enque(q,5);
  enque(q,13);
  enque(q,7);
  enque(q,2);
  cout << "Dequeued element: "<<Deque(q)<< endl;
  print(q);
  return 0;
}