/*
Given a binary string of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.

Example 1:

Input : S = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, 
there are 7 0s and 1 1s, so number 
of 0s - number of 1s is 6. 
Example 2:

Input: S = "111111"
Output: -1
Explanation: S contains 1s only 
Your task:
You do not need to read any input or print anything. The task is to complete the function maxSubstring(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubstring(string S)
	{
	    int *dp=new int[S.size()];
	    
	    for(int i=0;i<S.size();i++)
	    {
	        if(S[i]=='1')
	        {
	            dp[i]=-1;
	        }
	        else
	        {
	            dp[i]=1;
	        }
	    }
	    int max_num=-1;
	    if(max_num<dp[0])
	    {
	        max_num=dp[0];
	    }
	    for(int i=1;i<S.size();i++)
	    {
	        dp[i]=max(dp[i],dp[i]+dp[i-1]);
	        if(max_num<dp[i])
	        {
	            max_num=dp[i];
	        }
	    }
	    return max_num;
	    
	}
	
int main()
{
    string S;
    cin>>S;
    
    cout<<maxSubstring(S)<<endl;
}