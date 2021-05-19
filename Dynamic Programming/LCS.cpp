/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/

#include <bits/stdc++.h>
using namespace std;

int lcsIter(int x,int y,string s1,string s2)
{
    int **dp=new int*[x+1];
        
    for(int i=0;i<=x;i++)
    {
        dp[i]=new int[y+1];
    }
    
    for(int i=0;i<=x;i++)
    {
        dp[0][i]=0;
    }
     for(int i=0;i<=y;i++)
    {
        dp[i][0]=0;
    }
    
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(s1[x-i]==s2[y-j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
    
    
}

int lcs2Helper(int x,int y,string s1,string s2,int **dp)
{
    if(x==0 || y==0)
    {
        return 0;
    }
        
    if(dp[x][y]>-1)
    {
        return dp[x][y];
    }
        
    int ans;
    if(s1[0]==s2[0])
    {
        ans=1+lcs2Helper(x-1,y-1,s1.substr(1),s2.substr(1),dp);
    }
    else
    {
        ans=max(lcs2Helper(x-1,y,s1.substr(1),s2,dp),lcs2Helper(x,y-1,s1,s2.substr(1),dp));
    }
    dp[x][y]=ans;
    return ans;
}
    
int lcs(int x, int y, string s1, string s2)
{
        // your code here
    int **dp=new int*[x+1];
        
    for(int i=0;i<=x;i++)
    {
        dp[i]=new int[y+1];
        for(int j=0;j<=y;j++)
        {
            dp[i][j]=-1;
        }
    }
        
    int ans=lcs2Helper(x,y,s1,s2,dp);
        
    for(int i=0;i<=x;i++)
    {
        delete[] dp[i];
    }
        
    delete [] dp;
    return ans;
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    
    int x=s1.size();
    int y=s2.size();
    
    cout<<lcs(x,y,s1,s2)<<endl;
    cout<<lcsIter(x,y,s1,s2)<<endl;
	return 0;
}