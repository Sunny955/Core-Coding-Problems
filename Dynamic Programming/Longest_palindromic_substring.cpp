/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
    {
        int n=s.size();
        if(n<=1)
        {
           return s;
        }
        int dp[n][n];
        
        string ans=s.substr(0,1);
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                ans=s.substr(i,2);
            }
            else
            {
                dp[i][i+1]=0;
            }
        }
        
        
        int len=3;
        while(len<=n)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+len-1;
                if(j<n)
                {
                    if(s[i]==s[j])
                    {
                       dp[i][j]=dp[i+1][j-1];
                        
                        if(dp[i][j]==1)
                        {
                            ans=s.substr(i,len);
                        }
                            
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
            }
            len++;
        }
        return ans;
    }

int main()
{
    string input;
    cin>>input;
    cout<<longestPalindrome(input)<<endl;
}