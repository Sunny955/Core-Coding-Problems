/*
Given an array, print the Next Smaller Element (NSE) for every element. The Smaller smaller Element for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider next smaller element as -1. 
Examples: 
a) For any array, rightmost element always has next smaller element as -1. 
b) For an array which is sorted in increasing order, all elements have next smaller element as -1. 
c) For the input array [4, 8, 5, 2, 25}, the next smaller elements for each element are as follows.

Element       NSE
   4      -->   2
   8      -->   5
   5      -->   2
   2      -->   -1
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next smaller elements for each element are as follows.  

  Element        NSE
   13      -->    7
   7       -->    6
   6       -->    -1
   12     -->     -1
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int>& in)
{
    int n=in.size();
    vector<int> ans(n,0);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            ans[i]=-1;
            st.push(in[i]);
        }
        else
        {
            if(in[i]>st.top())
            {
                ans[i]=st.top();
                st.push(in[i]);
            }
            else
            {
                while(!st.empty() && in[i]<st.top())
                {
                    st.pop();
                }
                
                if(st.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=st.top();
                }
                st.push(in[i]);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> in(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    vector<int> ans=NSE(in);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}