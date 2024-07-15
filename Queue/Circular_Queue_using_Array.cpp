#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct circularQueue{
    int size;
    int fi;
    int bi;
    int *arr;
};

void initQueue(struct circularQueue *q,int size)
{
    q->size=size;
    q->fi=0;   //track forward index
    q->bi=0;   //track backward index
    q->arr=new int[q->size];
}

int isEmpty(struct circularQueue *q)
{
    if(q->fi==q->bi){return 1;}
    else{return 0;}
}

int isFull(struct circularQueue *q)
{
    if((q->fi+1)%q->size==q->bi){return 1;}
    else{return 0;}
}

void enque(struct circularQueue *q,int data)
{
  if(isFull(q)){cout<<"Circular Queue is Full."<<endl;}
  else
  {
    q->fi=(q->fi+1)%q->size;
    q->arr[q->fi]=data;
  }
}

int Deque(struct circularQueue *q)
{
  int a;
  if(isEmpty(q)){cout<<"Circular Queue is Empty."<<endl;return -1;}
  else
  {
    q->bi=(q->bi+1)%q->size;
    a=q->arr[q->bi];
  }
  return a;
}

void print(struct circularQueue *q) {
    int number = 0;
    int i = q->bi+1;
    while (i != q->fi) {
        cout << "Element " << number << ": " << q->arr[i] << endl;
        i = (i + 1) % q->size;
        number++;
    }
    cout<<"Element "<<number<<" : "<<q->arr[q->fi]<<endl;
}

int main()
{
  struct circularQueue *q=new struct circularQueue;
  initQueue(q,5);
  enque(q,5);
  enque(q,13);
  enque(q,7);
  enque(q,2);
  enque(q,11);
  cout << "Dequeued element: "<<Deque(q)<< endl;
  cout << "Dequeued element: "<<Deque(q)<< endl;
  cout << "Dequeued element: "<<Deque(q)<< endl;
  cout << "Dequeued element: "<<Deque(q)<< endl;
  /*cout << "Dequeued element: "<<Deque(q)<< endl;*/


  enque(q,17);
  enque(q,3);

  /*cout << "Dequeued element: "<<Deque(q)<< endl;
  cout << "Dequeued element: "<<Deque(q)<< endl;*/
  print(q);
  return 0;
}