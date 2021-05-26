/*
Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

 

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.
 

Example 2:

Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explaination: The optimal choice is to 
pick the 2nd and 4th element.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val[] and wt[] as input parameters and returns the maximum possible value.

 

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

 

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

*/

#include <bits/stdc++.h>
using namespace std;

int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W+ 1] = {0};
        
        dp[0] = 0;
            
        for(int i = 0; i < N; i++)
        {
            for(int j = wt[i]; j <= W; j++)
            {
                dp[j] = max(dp[j],dp[j - wt[i]]+val[i]);
            }
        }
            
        return dp[W];
    }

int main() 
{   
    int N,W;
    int val[N],wt[N];
    
    for(int i=0;i<N;i++)
    {
        cin>>val[i];
        cin>>wt[i];
    }
    cout<<knapSack(N,W,val,wt)<<endl;
	return 0;
}