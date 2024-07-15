#include<bits/stdc++.h>
#define ll long long
using namespace std;

void bucket_sort(double a[],int n)
{
    vector<double>b[n];  //empty bucket

    for(int i=0;i<n;i++)
    {
        int x=a[i]*n;
        b[x].push_back(a[i]);
    }

    for(int i=0;i<n;i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            a[index]=b[i][j];
            index++;
        }
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
    double a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bucket_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
  }
  return 0;
}