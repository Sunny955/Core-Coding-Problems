/* 
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

Examples : 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
This question has been asked at many places (See this and this)
*/
#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[],int n)
{
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(j>i)
    {
        if(arr[i]<0 && arr[j]>=0)
        {
            if(arr[i+1]>=0)
            {
                break;
            }
            else
            {
                int high=arr[j];
                int k=j;
                while(k>i)
                {
                    arr[k]=arr[k-1];
                    k--;
                }
                arr[k+1]=high;
                i+=2;
                j=n-1;
            }
        }
        else
        {
            break;
        }
    }
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
    rearrange(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
