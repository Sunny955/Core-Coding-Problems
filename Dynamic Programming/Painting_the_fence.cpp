/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6
Example 2:

Input:
N=2,  K=4
Output: 16

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted.(modulo 109 + 7)

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;
long long countWays(int n, int k)
{
    if(n==1)
    {
        return k;
    }
        
    long long same=k;
    long long diff=k*(k-1);
    long long tot=(same+diff);
        
    for(int i=3;i<=n;i++)
    {
        same=diff;
        diff=((k-1)*tot)%mod;
        tot=(same+diff)%mod;
    }
        
    return tot;
}


int main()
{
    int n,k;
    cin>>n>>k;
    
    cout<<countWays(n,k)<<endl;
}