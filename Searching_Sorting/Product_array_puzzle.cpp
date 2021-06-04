/*
Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Example 2:

Input:
n = 2
nums[] = {12,0}
Output:
0 12

Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() that takes array nums[] and n as input parameters and returns a list of n integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
    {
       int count=0;
         long long int product=1;
         vector<long long int> prod(n,1);
         for(int i=0;i<n;i++)
         {
             if(nums[i]==0)
             {
                 count++;
             }
         }
         if(count==1)
         {
            for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    product*=nums[i];
                }
            }
            
            for(int i=0;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    prod[i]=0/nums[i];
                }
                else
                {
                    prod[i]=product;
                }
            }
            
         }
         else if(count>1)
         {
            for(int i=0;i<n;i++)
            {
                prod[i]=0;
            }
         }
         else
         {
             for(int i=0;i<n;i++)
             {
                 prod[i]=product/nums[i];
             }
         }
         return prod;
    }
    
    int main()
    {
        int n;
        cin>>n;
        vector<long long int> nums(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        vector<long long int> ans=productExceptSelf(nums,n);
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        
    }