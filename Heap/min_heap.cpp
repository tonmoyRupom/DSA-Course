#include<bits/stdc++.h>
#define ll long long
using namespace std;
void minHeapify(int a[],int heapSize,int i)
{
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    //If left child is smaller than the root
    if(l<heapSize && a[l]<a[smallest])
    {
        smallest=l;
    }

    //If right child is smaller than the smaller so far
    if(r<heapSize && a[r]<a[smallest])
    {
        smallest=r;
    }

    //if smallest is not root
    if(smallest!=i)
    {
        swap(a[i],a[smallest]);
        minHeapify(a,heapSize,smallest);
    }
}

void BuildMinHeap(int a[],int n)
{
    int start=(n/2)-1;

    for(int i=start;i>=0;i--)
    {
        minHeapify(a,n,i);
    }
}

void decreaseKey(int a[],int i,int value)
{
    a[i]=value;
    while(i!=0 && a[(i-1)/2]>a[i])
    {
        swap(a[(i-1)/2],a[i]);
        i=(i-1)/2;
    }
}

int extractMin(int a[],int& heapSize)
{
    //Check for empty heap
    if(heapSize<=0)
    {
        return INT_MAX;
    }

    if(heapSize==1)
    {
        heapSize--;
        return a[0];
    }

    int min=a[0];
    a[0]=a[heapSize-1];
    heapSize--;
    minHeapify(a,heapSize,0);
    return min;
}

void deleteKey(int a[],int &heapSize,int index)
{
    decreaseKey(a,index,INT_MIN);
    extractMin(a,heapSize);
}

void insertKey(int a[],int &heapSize,int val)
{
    if(heapSize==INT_MAX)
    {
        cout<<"OverFlow..Insertion not possible!!";
    }

    heapSize++;
    int i=heapSize-1;
    a[i]=val;

    while(i!=0 && a[(i-1)/2]>a[i])
    {
        swap(a[(i-1)/2],a[i]);
        i=(i-1)/2;
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    BuildMinHeap(a,n);
    cout << a[0] << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // Delete at index
    deleteKey(a, n, 2);
    cout << "HeapSize after Deletion: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // Insert new key
    insertKey(a, n, 15);
    insertKey(a, n, 5);
    cout << "HeapSize after insertion: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;

  return 0;
}