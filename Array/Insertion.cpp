#include<bits/stdc++.h>
#define ll long long
using namespace std;
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    } 
    cout<<endl;
}
int indInsertion(int a[],int n,int index,int data)
{
    if(n>=100){return -1;}
    else
    {
        for(int i=n-1;i>=index;i--)
        {
            a[i+1]=a[i];
        }
        a[index]=data;
        
        return 1;
    }
}

int indDelection(int a[],int n,int index)
{
    if(n==0){return -1;}
    else
    {
        for(int i=index;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        return 1;
    }
}
int main()
{
    int n;
  cin>>n;
  int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    display(a,n);
    cout<<"After insertion"<<endl;
    int q,q1;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int index,data;
        cin>>index>>data;
        int r=indInsertion(a,n,index,data);
        if(r==-1){cout<<"Not Possible"<<endl;}
        else
        {
            n=n+1;
            display(a,n);
        }
    }
    cout<<"After deletion\n";
    cin>>q1;
    for(int i=0;i<q1;i++)
    {
        int index;
        cin>>index;
        int r=indDelection(a,n,index);
        if(r==-1){cout<<"Not possible\n";}
        else
        {
            n=n-1;
            display(a,n);
        }
    }
  return 0;
}