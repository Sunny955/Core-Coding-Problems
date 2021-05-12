/*
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Example 1:

â€‹Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
Explanation:
To bring elements 2, 1, 3 together, swap element '5' with '3'
such that final array will be- arr[] = {2, 1, 3, 6, 5}

â€‹Example 2:

Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
Output :  2 
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function minSwap() that takes an array (arr), sizeOfArray (n), an integer K, and return the minimum swaps required. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


*/


#include<bits/stdc++.h>
using namespace std;

int minSwap(int *arr, int n, int k)
{
    int count=0;
    int ans= INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        {
            count++;
        }
    }
    int bad=0;
    for(int i=0;i<count;i++)
    {
        if(arr[i]>k)
        {
            bad++;
        }
        ans=bad;
    }
    
    for(int i=0;i<n-count;i++)
    {
        if(arr[i]>k)
        {
            bad--;
        }
        if(arr[i+count]>k)
        {
            bad++;
        }
        ans=min(ans,bad);
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    int ans = minSwap(arr,n,k);
    cout<<ans<<endl;
}