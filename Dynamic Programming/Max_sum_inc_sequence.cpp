/*
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


*/

#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)  
{  
	   
	    int *dp=new int[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        dp[i]=arr[i];
	    }
	    int max_sum=dp[0];
	    int res;
	    for(int i=1;i<n;i++)
	    {
	        res=INT_MIN;
	        for(int j=i-1;j>=0;j--)
	        {
	            if(arr[i]>arr[j])
	            {
	                res=max(res,dp[j]);
	            }
	        }
	        if(res>0)
	        {
	            dp[i]+=res;
	        }
	        
	        if(dp[i]>max_sum)
	        {
	            max_sum=dp[i];
	        }
	    }
	    return max_sum;
	    
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
	cout<<maxSumIS(arr,n)<<endl;
	return 0;
}
