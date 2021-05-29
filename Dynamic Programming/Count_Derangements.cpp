/*
A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.

Examples : 

Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one 
possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9
possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
{1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
*/
#include <bits/stdc++.h>
using namespace std;

int CountDer(int n)
{
    int dp[n+1]={};
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    
    for(int i=3;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    
    cout<<CountDer(n)<<endl;
}