/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5. 
 

Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.
Note: If the number x is not found in the array just return both index as -1.

 

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x )
{
    int f=-1,s=-1;
    int l=0,mid,h=n-1;
    
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==x)
        {
            f=mid;
            h=mid-1;
        }
        else if(arr[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    l=0,h=n-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==x)
        {
            s=mid;
            l=mid+1;
        }
        else if(arr[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    vector<int> ans(2,-1);
    ans[0]=f;
    ans[1]=s;
    return ans;
}

int main()
{
    int n,x;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>x;
    vector<int> ans=find(arr,n,x);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}