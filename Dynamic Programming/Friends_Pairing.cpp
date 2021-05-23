/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

Example 2: 

Input: N = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countFriendsPairings() which accepts an integer n and return number of ways in which friends can remain single or can be paired up.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

long long int mod=1000000007;
int helper(int n,int *dp)
{
    if(n<=2)
    {
        return n;
    }
        
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans=-100;
    ans=(helper(n-1,dp)%mod+(n-1)%mod*helper(n-2,dp)%mod)%mod;
    dp[n]=ans;
    return ans;
}

int countFriendsPairings(int n) 
{ 
    int *dp=new int[n+1]();
        
    return helper(n,dp);
}

int main()
{
	int n;
	cin>>n;
	cout<<countFriendsPairings(n)<<endl;
	return 0;
}