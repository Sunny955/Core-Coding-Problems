/*
Given an integer array containing both negative and positive integers. Find and return the sum of contiguous sub-array with maximum sum.
Input Format :
Line 1: Integer N, size of input array
Line 2: N integers, elements of input array (separated by space)
Output Format :
Maximum Sum of the contiguous sub-array
Contraints :
1 = N = 1000
-100 = A[i] <= 100
Sample Input 1:
3
1 2 3
Sample Output 1:
6
Sample Input 2:
4
-1 -2 -3 -4
Sample Output 2:
-1
*/


#include <bits/stdc++.h>
using namespace std;

int findSum(int *arr,int n)
{
    int curr_sum=arr[0];
    int max_sum=arr[0];
    
    for(int i=1;i<n;i++)
    {
       if(curr_sum<0)
       {
           curr_sum=0;
       }
        curr_sum+=arr[i];
        
        if(curr_sum>max_sum)
        {
            max_sum=curr_sum;
        }
        
    }
    return max_sum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findSum(arr,n);

}