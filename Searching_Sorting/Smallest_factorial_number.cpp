/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).
*/
#include<bits/stdc++.h>
using namespace std;

int find_zeros(int n)
        {
            int count=0;
            if(n<5)
            {
                return 0;
            }
            for(int i=5;n/i>=1;i*=5)
            {
                count+=n/i;
                
            }
            return count;
        }
        int findNum(int n)
        {
            int l=1,h=n*5,ans=-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                int c=find_zeros(mid);
                if(c>=n)
                {
                    ans=mid;
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                
            }
            return ans;
        }

int main()
{
    int n;
    cin>>n;
    cout<<findNum(n)<<endl;
}