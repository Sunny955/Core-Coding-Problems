/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countRev() which takes the string S as input parameter and returns the minimum number of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).
*/
#include <bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    if(s.size()%2!=0)
    {
        return -1;
    }
    int count1=0,count2=0;
    for(int i=0;i<s.size();i++)
    {
        if(i==0 && s[i]=='}')
        {
            count2++;
        }
        else if(s[i]=='{')
        {
            count1++;
        }
        else if(s[i]=='}')
        {
            if(count1>0)
            {
                count1--;
            }
            else
            {
                count2++;
            }
        }
    }
    
    if(count1==0 || count2==0)
    {
        return (count1+count2)/2;
    }
    else
    {
        int ans1,ans2;
        ans1=count1/2;
        count1=count1-2*ans1;
        ans2=count2/2;
        count2=count2-2*ans2;
        
        if(count1%2!=0)
        {
            return ans1+ans2+2;
        }
        else
        {
            return ans1+ans2;    
        }
        
    }
    
    return -1;
}

int main() 
{
    string s;
    cin>>s;
    cout<<countRev(s)<<endl;
	return 0;
}