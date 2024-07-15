#include<bits/stdc++.h>
#define ll long long
using namespace std;

void print(int n)
{
    if(n>0)
    {
        print(n-1);
        cout<<n<<" ";
        print(n-1);
    }
}
int main()
{
   print(4);
  return 0;
}