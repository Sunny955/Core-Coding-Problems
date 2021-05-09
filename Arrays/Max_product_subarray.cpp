/* 
Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is  6, -3, -10 which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is 2, 3, 4, 5 which gives product as 120.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
*/

#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n)
{
	  long long prod=arr[0];
	  long long max_prod=arr[0];
	  long long min_prod=arr[0];
	    
	  for(int i=1;i<n;i++)
	  {
	     if(arr[i]<0)
	     {
	       swap(max_prod,min_prod);
	     }
	     max_prod = max((long long)arr[i],max_prod*arr[i]);
	     min_prod = min((long long)arr[i],min_prod*arr[i]);
	       
	     prod=max(prod,max_prod);
	  }
	  return prod;
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
    long long ans = maxProduct(arr,n);
    cout<<ans<<endl;
}

