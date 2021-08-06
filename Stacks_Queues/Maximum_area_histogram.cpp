/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 1012
*/
#include<bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
        long long ans=INT_MIN;
        vector<long long> left(n);
        vector<long long> right(n);
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                left[i]=0;
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                left[i]=st.empty()? 0:st.top()+1;
                st.push(i);
            }
            
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                right[i]=n-1;
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                right[i]=st.empty() ? n-1:st.top()-1;
                st.push(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,arr[i]*(right[i]-left[i]+1));;
        }
        return ans;
        
}
int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<getMaxArea(arr,n)<<endl;
}