#include<bits/stdc++.h>
#define ll long long
using namespace std;
void print(int i,int n)
{  
    if(i==n+1){return;}
    cout<<i<<" ";
    i++;
    print(i,n);
}

int sum(int n)
{
    int s;
    if(n==1){return 1;}
    else{s=n+sum(n-1);}
    return s;
}

void fibo(int pre,int num,int n)
{
    static int i=1;
    if(i==n){return;}
    else
    {
        int temp=pre+num;
        pre=num;
        num=temp;
        cout<<temp<<" ";
        i++;
        fibo(pre,num,n);
    }
}

int digit_number(int n)
{
    static int digit=0;
    if(n==0){return digit;}
    else
    {
        digit++;
        n=n/10;
        digit_number(n);
    }
}

int g_c_d(int a,int b)
{
    if(a<=b)
    {
        if(a==0){return b;}
        else
        {
            int rem=b%a;
            b=a;
            a=rem;
            gcd(a,b);
        }
    }
    else
    {
        if(b==0){return a;}
        else
        {
            int rem=a%b;
            a=b;
            b=rem;
            gcd(a,b);
        }
    }
}

int fact(int n)
{
    int f;
    if(n==1){return 1;}
    else
    {
        f=n*fact(n-1);
    }
    return f;
}
int palindrome(string s)
{
    static int i=0,j=s.size()-1;
    if(s[i]!=s[j]){return 0;}
    else if(s[i]==s[j] && i<j)
    {
        i++;
        j--;
    }
    return 1;
}

int main()
{
    /*ll n;
    cin>>n;*/
    /*ll pre=0,num=1;
    cout<<"1 ";
    fibo(pre,num,n);
    cout<<"The digit of n is:"<<digit_number(n)<<endl;*/
    /*ll a,b;
    cin>>a>>b;
    cout<<"GCD of a and b is: "<<g_c_d(a,b)<<endl;*/

    /*ll r=fact(n);
    cout<<"Factorial of "<<n<<" is:"<<r<<endl;*/
    string s;
    cin>>s;
    if(palindrome(s)){cout<<"The string is a palindrome"<<endl;}
    else{cout<<"The string is not a palindrome"<<endl;}
  return 0;
}