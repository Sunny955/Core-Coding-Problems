/*
Remove the middle element of stack in O(1) space and O(n) time
*/

#include<bits/stdc++.h>
using namespace std;

void RemoveMiddle(stack<int>& st,int ind,int mid)
{
    if(ind==mid)
    {
        st.pop();
        return;
    }    
    int a=st.top();
    st.pop();
    ind++;
    RemoveMiddle(st,ind,mid);
    st.push(a);
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

    RemoveMiddle(st,0,n/2);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}