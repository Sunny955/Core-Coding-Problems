/*
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
*/
#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
        vector<long long> ans(n,0);
        
        stack<long long> st;
        int i=n-1;
        while(i>=0)
        {
            if(i==n-1)
            {
                st.push(arr[i]);
                ans[i]=-1;
            }
            else
            {
                if(!st.empty() && st.top()>arr[i])
                {
                    ans[i]=st.top();
                    st.push(arr[i]);
                }
                else if(!st.empty() && arr[i]>st.top())
                {
                    while(!st.empty())
                    {
                        if(arr[i]<st.top())
                        {
                            break;
                        }
                        st.pop();
                    }
                    
                    if(!st.empty())
                    {
                        ans[i]=st.top();
                        st.push(arr[i]);
                    }
                    else
                    {
                        ans[i]=-1;
                        st.push(arr[i]);
                    }
                
                }
            }
            i--;
        }
        
        return ans;
}

int main()
{
    int n;
    cin>>n;
    
    vector<long long> arr;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<long long> ans=nextLargerElement(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}