/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function sb() which takes the array A[], its size N and an integer X as inputs and returns the required ouput.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/


#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x)
{
    int sum=0;
    int ans=INT_MAX;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>x)
        {
            return 1;
        }
        sum+=arr[i];
        if(sum>x)
        {
            ans=min(i-j+1,ans);
        }
        while(sum>=x)
        {
            sum-=arr[j];
            j++;
            if(sum>x)
            {
                ans=min(i-j+1,ans);
            }
        }
    }
    return ans;
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
    int x;
    cin>>x;
    int ans=sb(arr,n,x);
    cout<<ans<<endl;
}