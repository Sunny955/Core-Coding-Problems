/*Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1. */


#include <bits/stdc++.h>
using namespace std;

int getPairCounts(int arr[],int n,int k)
{
    int count=0;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
        if(map.find(k-arr[i])!=map.end())
        {
            count+=map[k-arr[i]];
        }
        map[arr[i]]++;
    }
    return count;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	int k;
	cin>>k;
	int ans=getPairCounts(arr,n,k);
	cout<<"----> "<<ans<<endl;
	return 0;
}