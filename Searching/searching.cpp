#include<bits/stdc++.h>
#define ll long long
using namespace std;
int linear_search(int a[],int n,int element)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int a[],int n,int element)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==element)
        {
            return mid;
        }
        else if(a[mid]<element)
        {
            low=mid+1;
        }
        else if(a[mid]>element)
        {
            high=mid-1;
        }
    }
    return -1;
}


int main()
{
  int n,q;
  cin>>n>>q;
  int a[100];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
    for(int i=0;i<q;i++)
    {
        int type,element;             //1 for linear search and 2 for binary search
        cin>>type>>element;
        if(type==1)
        {
            int r=linear_search(a,n,element);
            if(r!=-1)
            {
                cout<<"Element "<<element<<" Index is "<<r<<endl; 
            }
            else
            {
                cout<<"Element is not found"<<endl;
            }
        }
        else if(type==2)
        {
            sort(a,a+n);      //Array must be sorted
            int r=binary_search(a,n,element);
            if(r!=-1)
            {
                cout<<"Element "<<element<<" Index is "<<r<<endl; 
            }
            else
            {
                cout<<"Element is not found"<<endl;
            }
        }
    }
  return 0;
}