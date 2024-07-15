#include<bits/stdc++.h>
#define ll long long
using namespace std;


void printarray(int a[],int x)
{
    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void count_sort(int a[],int x)
{
    int max=INT_MIN;
    for(int i=0;i<x;i++)
    {
        if(a[i]>max){max=a[i];}
    }
    int *count_array=new int[max+1];

    for(int i=0;i<=max;i++)
    {
        count_array[i]=0;
    }

    for(int i=0;i<x;i++)
    {
        count_array[a[i]]++;
    }

    int i=0;   //counter for count array
    int j=0;     //counter for given array
    while(i<=max)
    {
        if(count_array[i]>0)
        {
            while(count_array[i]>0)
            {
                a[j]=i;
                j++;
                count_array[i]--;
            }
            i++;
        }
        else{i++;}
    }
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    printarray(a,n);

    count_sort(a,n);
    printarray(a,n);

  return 0;
}