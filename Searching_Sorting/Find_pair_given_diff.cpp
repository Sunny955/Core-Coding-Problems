/*
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes array arr, size of the array L and N as input parameters and returns True if required pair exists, else return False.

Expected Time Complexity: O(L* Log(L)).
Expected Auxiliary Space: O(1).
*/

#include<bits/stdc++.h>
using namespace std;

int Search(int *a,int l,int r,int k)
{
    if(l>r)
    {
        return -1;
    }
    
    int mid=(l+r)/2;
    
    if(a[mid]==k)
    {
        return mid;
    }
    
    if(a[mid]>k)
    {
        return Search(a,l,mid-1,k);
    }
    
    return Search(a,mid+1,r,k);
}
bool findPair(int arr[], int size, int n)
{
    sort(arr,arr+size);
    int max_val=arr[size-1];
    bool ans=false;
    int index;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]+n<=max_val)
        {
            index=Search(arr,0,size-1,arr[i]+n);
            if(index>0)
            {
                ans=true;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int n;
    cin>>n;
    if(findPair(arr,size,n))
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}