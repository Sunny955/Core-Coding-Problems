#include<bits/stdc++.h>
using namespace std;

bool isValid(int *arr,int n,int m,int mid)
    {
        int student=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum>mid)
            {
                student++;
                sum=arr[i];
            }
            
            if(student>m)
            {
                return false;
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        if(m>n)
        {
            return -1;
        }
        
        int start=INT_MIN;
        int end=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>start)
            {
                start=arr[i];
            }
            end+=arr[i];
        }
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isValid(arr,n,m,mid)==true)
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return res;
    }

int main()
{
    int n,m;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cin>>m;
    cout<<findPages(arr,n,m)<<endl;
}