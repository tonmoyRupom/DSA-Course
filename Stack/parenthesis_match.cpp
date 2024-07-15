#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct stackNode{
    char c;
    stackNode *next; 
};

stackNode* top=NULL;

void push(char ch)
{
    stackNode *p=new stackNode();
    p->c=ch;
    p->next=NULL;
    if(top==NULL){top=p;}
    else
    {
        p->next=top;
        top=p;
    }
}

char pop()
{
    if (top == NULL) {
        return '\0'; // Return null character for empty stack
    }
    else
    {
        char ch=top->c;
        stackNode *q=top;
        top=top->next;
        free(q);
        return ch;
    }
}

int isEmpty()
{
    if(top==NULL){return 1;}
    else{return 0;}
}

int parenthesisMatch(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){push(s[i]);}
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty()==1) {
                cout << "Not Matched" << endl;
                return -1;
            }
            char ch = pop();
            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '[')) {
                cout << "Not Matched" << endl;
                return -1;
            }
        }
    }
    if(isEmpty()==1){return 1;}
    else{return 0;}
}
int main()
{
    string exp;
    cin>>exp;
    if(parenthesisMatch(exp)==1){cout<<"The parenthesis is matching"<<endl;}
    else{cout<<"The parenthesis is not Valid"<<endl;}
  return 0;
}