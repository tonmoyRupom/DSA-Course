#include<bits/stdc++.h>
#define ll long long
using namespace std;

int max_value(int a[],int n)
{
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>mx){mx=a[i];}
    }
    return mx;
}

void count_sort(int arr[],int n,int exp)
{
    int output[n];
    int count[10]={0};

    for(int i=0;i<n;i++)    //Store count of occurance
    {
        count[(arr[i]/exp)%10]++;
    }

    // Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    //Biuld the output array
    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}


void radix_sort(int a[],int n)
{
    int m=max_value(a,n);   //get the maximum value of the array

    for(int exp=1;(m/exp)>0;exp*=10)
    {
        count_sort(a,n,exp);
    }
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radix_sort(a,n);
    print(a,n);
  }
  return 0;
}