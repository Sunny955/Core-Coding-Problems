/*
Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
Examples : 

Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013

Input: arr[] = {100, 1000, 100, 1000, 1}
Output: 2101
100 + 1000 + 1000 + 1 = 2101

Input: arr[] = {1, 1, 1, 1, 1}
Output: 4

Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 27
*/

#include<bits/stdc++.h>
using namespace std;

int CountTot(int *arr,int n)
{
    int max_val;
    int *dp=new int[n];
    dp[0]=arr[0];
    dp[1]=arr[1]+dp[0];
    dp[2]=max(arr[2]+arr[1],arr[2]+arr[0]);
    
    max_val=max(dp[0],max(dp[1],dp[2]));
    
    for(int i=3;i<n;i++)
    {
        dp[i]=max(max(arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]),dp[i-1]);
        if(dp[i]>max_val)
        {
            max_val=dp[i];
        }
    }
    return max_val;
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<CountTot(arr,n)<<endl;
}