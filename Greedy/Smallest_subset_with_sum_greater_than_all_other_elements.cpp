/*
Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.
Examples : 
 

Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of
this subset is greater than all
other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not 
enough. We can pick elements with 
values 1, 2 or 2, 2. In any case, 
the minimum count is 2.
*/
#include<bits/stdc++.h>
using namespace std;

int SmallestSubset(int *arr,int n)
{
    if(n==1)
    {
        return 1;
    }
    int sum_tot=0;
    for(int i=0;i<n;i++)
    {
        sum_tot+=arr[i];
    }
    sort(arr,arr+n);
    int i=0,j=n-2;
    int ri_sum=0,le_sum=0;
    while(j>=i)
    {
        ri_sum+=arr[j+1];
        le_sum=sum_tot-ri_sum;
        if(ri_sum>le_sum)
        {
            break;
        }
        j--;
    }
    return n-1-j;
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
    cout<<SmallestSubset(arr,n)<<endl;
}