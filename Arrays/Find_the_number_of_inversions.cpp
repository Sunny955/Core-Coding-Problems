/* 
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.

*/

#include<bits/stdc++.h>
using namespace std;

long long merge(long long arr[],long long low,long long mid,long long high)
{
    long long N1=mid-low+1;
    long long N2=high-mid;
    
    long long Left[N1];
    long long Right[N2];
    
    for(long long i=0;i<N1;i++)
    {
        Left[i]=arr[low+i];
    }
    
    for(long long j=0;j<N2;j++)
    {
        Right[j]=arr[mid+j+1];
    }
    long long i=0,j=0,k=low;
    long long res=0;
    while(i<N1 && j<N2)
    {
        if(Left[i]<=Right[j])
        {
            arr[k++]=Left[i++];
        }
        else
        {
            arr[k++]=Right[j++];
            res+=(N1-i);
        }
    }
    while(i<N1)
    {
        arr[k++]=Left[i++];
    }
    while(j<N2)
    {
        arr[k++]=Right[j++];
    }
    return res;
}

long long mergeSort(long long arr[],long long low,long long high)
{
    long long res=0;
    if(high>low)
    {
        int mid = low + (high-low)/2;
        res+=mergeSort(arr,low,mid);
        res+=mergeSort(arr,mid+1,high);
        res+=merge(arr,low,mid,high);
    }
    return res;
}

long long inversionCount(long long arr[], long long N)
{

    return mergeSort(arr,0,N-1);
}

int main()
{
    long long N;
    cin>>N;
    
    long long arr[N];
    for(long long i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    long long ans = inversionCount(arr,N);
    cout<<ans<<endl;
}