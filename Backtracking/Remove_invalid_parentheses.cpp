/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
*/
#include<bits/stdc++.h>
using namespace std;

int getMinInValid(string s)
{
        stack<char> stck;
        int i=0;
        while(i < s.size())
        {
            if(s[i] == '(')
                stck.push('(');
            else if(s[i] == ')')
            {
                if(stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        return stck.size();
}
    
    
    vector<string> res;
    unordered_map<string,int> mp;
void solve(string s,int minInv)
{
        if(mp[s] != 0)
            return;
        else
            mp[s]++;
        if(minInv == 0)
        {
            if(getMinInValid(s) == 0)
                res.push_back(s);
            return;
        }
        
        for(int i=0;i<s.size();i++)
        {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right,minInv-1);
        }
            
        return;
}
    
vector<string> removeInvalidParentheses(string s) 
{
        solve(s,getMinInValid(s));
        return res;
}

int main()
{
    string s;
    cin>>s;
    vector<string> ans=removeInvalidParentheses(s);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
}