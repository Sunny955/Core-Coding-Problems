/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
*/

#include<bits/stdc++.h>
using namespace std;

int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(),pairs.end());
        vector<int> dp(pairs.size(),0);
        dp[0]=1;
        int max_len=1;
        for(int i=1;i<pairs.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]++;
            if(max_len<dp[i])
            {
                max_len=dp[i];
            }
        }
        return max_len;
    }
    
int main()
{
    int R,C;
    cin>>R>>C;
    
    vector<vector<int>> pairs(R,vector<int>(C,0));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>pairs[i][j];   
        }
    }
    cout<<findLongestChain(pairs)<<endl;
}