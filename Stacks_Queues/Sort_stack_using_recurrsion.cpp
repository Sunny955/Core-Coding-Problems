/*
Sort a stack using recurrsion
3 7 2 1 5 ---> 1 2 3 5 7
*/
#include<bits/stdc++.h>
using namespace std;

void InsertPos(stack<int>& st,int top)
{
    if(st.empty() || st.top()<top)
    {
        st.push(top);
        return;
    }
    
    int ele=st.top();
    st.pop();
    InsertPos(st,top);
    st.push(ele);
}

void Sort(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    int top=st.top();
    st.pop();
    Sort(st);
    
    InsertPos(st,top);
}

int main()
{
    int n;
    cin>>n;
    int a;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        st.push(a);
    }
    Sort(st);
    
    for(int i=0;i<n;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}