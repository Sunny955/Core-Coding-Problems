/*
Quesn not available 
Given the array find if the given sum is possible using the subset of array

for eg: 
arr[]: 1 3 7 8 9
sum: 11

OUTPUT: YES

Explaination: 3+8=11 Therefore atleast one subset is possible with the given sum
*/

#include<bits/stdc++.h>
using namespace std;

int helper(int *arr,int n,int sum,int **dp)
{
    if(sum==0)
    {
        return 1;
    }
    if(n<=0 && sum>0)
    {
        return 0;
    }
    
    if(dp[n][sum]!=-1)
    {
        return dp[n][sum];
    }
    int ans=-100;
    if(arr[n-1]<=sum)
    {
        ans=max(helper(arr,n-1,sum-arr[n-1],dp),helper(arr,n-1,sum,dp));
    }
    else
    {
        ans=helper(arr,n-1,sum,dp);
    }
    dp[n][sum]=ans;
    return ans;
}

bool findSubset(int *arr,int n,int sum)
{
    
    int **dp=new int*[n+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[sum+1];
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=-1;
        }
    }
    return helper(arr,n,sum,dp);
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
    
    int sum;
    cin>>sum;
    
    cout<<findSubset(arr,n,sum)<<endl;
    return 0;
}