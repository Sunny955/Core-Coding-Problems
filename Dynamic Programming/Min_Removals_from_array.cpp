/*
Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements. 

Examples: 

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5
*/
#include <bits/stdc++.h>
using namespace std;

int MinRemovalHelper(int *arr,int i,int j,int k,int **dp)
{
    if(i>=j)
    {
        return 0;
    }
    
    if(arr[j]-arr[i]<=k)
    {
        return 0;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=-100;
    if(arr[j]-arr[i]>k)
    {
        ans=1+min(MinRemovalHelper(arr,i+1,j,k,dp),MinRemovalHelper(arr,i,j-1,k,dp));
    }
    dp[i][j]=ans;
    return ans;
    
}

int MinRemoval(int *arr,int n,int k)
{
    sort(arr,arr+n);
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    return MinRemovalHelper(arr,0,n-1,k,dp);
}

int main()
{
    int N,K;
    cin>>N;
    
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cin>>K;
    cout<<MinRemoval(arr,N,K)<<endl;
}