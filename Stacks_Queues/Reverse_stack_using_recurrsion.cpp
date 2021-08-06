/*
Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)
*/
#include<bits/stdc++.h>
using namespace std;

void InsertEnd(stack<int>& st,int top)
{
    if(st.empty())
    {
        st.push(top);
        return;
    }
    
    int new_top=st.top();
    st.pop();
    InsertEnd(st,top);
    st.push(new_top);
}

void Reverse(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    int top=st.top();
    st.pop();
    
    Reverse(st);
    InsertEnd(st,top);
}

int main()
{
    int n;
    cin>>n;
    stack<int> st;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        st.push(a);
    }
    Reverse(st);
    
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}