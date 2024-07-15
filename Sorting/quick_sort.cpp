#include<bits/stdc++.h>
#define ll long long
using namespace std;

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low+1;
    int j=high;
    do{
    while(a[i]<=pivot)
    {
        i++;
    }
    while(a[j]>pivot)
    {
        j--;
    }
    if(i<j)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }while(i<j);

    //swap a[low] and a[j]
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int partionindex;  //Index of pivot adter partition
        partionindex=partition(a,low,high);  //1
        //printArray(a,9);
        quicksort(a,low,partionindex-1);    //sort left subarray
        quicksort(a,partionindex+1,high);     //sort right subarray
    }    
}

//3,5,2,13,12,3,2,13,45
//3,5i,2,13,12,3,2j,13,45
//3,2i,2,13i,12,3j,5,13,45
//3,2i,2,3j,12i,13,5,13,45  fisrt call to parition return 3
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    printArray(a,n);
    quicksort(a,0,n-1);
    printArray(a,n);  
  return 0;
}
