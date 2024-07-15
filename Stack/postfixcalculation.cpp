#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct stackNode {
    int val;
    stackNode *next;
};

stackNode* top = NULL;

void push(int x) {
    stackNode *p = new stackNode();
    p->val = x;
    p->next = top;
    top = p;
}

int pop() {
    if (top == NULL) {
        return 0; // Return null character for empty stack
    } else {
        int x = top->val;
        stackNode *q = top;
        top = top->next;
        delete q; // Deallocate memory for popped node
        return x;
    }
}

int postfix_calculation(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'){push(s[i]-'0');}
        else
        {
            int op2=pop();
            int op1=pop(),x;
            if(s[i]== '+')
            {
                x=op1+op2;
            }

            else if(s[i]== '-')
            {              
                x=op1-op2;
            }

            else if(s[i]=='*')
            {
                
                x=op1*op2;
                
            }

            else if(s[i]=='/')
            {
                
                x=op1/op2;
            }
            push(x);
        }
    }
    return pop();
}

int main() {
    string s;
    cin >> s;
    int x=postfix_calculation(s);
    cout<<x<<endl;
    return 0;
}
