/*
Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.

Example 1:

Input:
N = 5
Output: 42
Example 2:

Input:
N = 4
Output: 14
Your Task:
Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

#include<bits/stdc++.h>
using namespace std;

cpp_int helper(int n,cpp_int *dp)
{
        if (n <= 1)
        {
            return 1;
        }
        
        if(dp[n]!=0)
        {
            return dp[n];
        }
        cpp_int result = 0;
        for (int i=0; i<n; i++)
        {
          result += helper(i,dp)*helper(n-i-1,dp);
          dp[n]=result;
        }
       return result;
}
    
cpp_int findCatalan(int n) 
{
        cpp_int dp[n+1]={0};
        return helper(n,dp);
}

int main()
{
    int n;
    cin>>n;
    
    cout<<findCatalan(n)<<endl;
}