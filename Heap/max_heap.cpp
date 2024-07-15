#include<bits/stdc++.h>
#define ll long long
using namespace std;

void maxHeapify(int a[],int heapSize,int i)
{
    int largest=i;   //
    int l=2*i+1;     //Left-Child
    int r=2*i+2;     //Right-Child

    //If left child is larger than root
    if(l<heapSize && a[l]>a[largest])
    {
        largest=l;
    }

    //If right child is larger than larger so far
    if(r<heapSize && a[r]>a[largest])
    {
        largest=r;
    }

    //If largest is not root
    if(largest!=i)
    {
        swap(a[i],a[largest]);

        //Recursively heapify the affected sub-Tree
        maxHeapify(a,heapSize,largest);
    }
}

void BuildMaxHeap(int a[],int n)
{
    //Index of last non-leaf node
    int start=(n/2)-1;

    for(int i=start;i>=0;i--)
    {
        maxHeapify(a,n,i);
    }
}

int extractMax(int a[],int& heapSize)
{
    //Check for empty heap
    if(heapSize<=0)
    {
        return INT_MIN;
    }

    if(heapSize==1)
    {
        heapSize--;
        return a[0];
    }

    int max=a[0];
    a[0]=a[heapSize-1];
    heapSize--;
    maxHeapify(a,heapSize,0);

    return max;
}

void increaseKey(int a[],int i,int value)
{
    a[i]=value;
    while(i!=0 && a[(i-1)/2]<a[i])
    {
        swap(a[(i-1)/2],a[i]);
        i=(i-1)/2;
    }
}

void deleteKey(int a[],int &heapSize,int i)
{
    increaseKey(a,i,INT_MAX);
    extractMax(a,heapSize);
}

void insertKey(int a[],int& heapSize,int val)
{
    //Check for heap overflow
    if(heapSize==INT_MAX)
    {
        cout<<"Overflow.Could not insert";
        return;
    }

    //Insert the new key at the end
    heapSize++;
    int i=heapSize-1;
    a[i]=val;

    //Fix the heap property if violated
    while(i!=0 && a[(i-1)/2]<a[i])
    {
        swap(a[(i-1)/2],a[i]);
        i=(i-1)/2;
    }
}

int main()
{
  int n,maxSize=15;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];        //3 10 12 8 2 14
  }

  BuildMaxHeap(a,n);

  cout<<a[0]<<endl;     //Printing the maximum element
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    //Delete at index  
    deleteKey(a,n,5);
    cout<<"HeapSize after Deletion: "<<n<<endl;      //HeapSize after Deletion
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    //insert new key
    insertKey(a,n,15);
    insertKey(a,n,5);
    cout<<"HeapSize after insertion: "<<n<<endl;      //HeapSize after insertion
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
  return 0;
}