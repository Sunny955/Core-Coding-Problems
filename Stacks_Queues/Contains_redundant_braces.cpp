/*
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
Example: 
 

Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.
*/
#include<bits/stdc++.h>
using namespace std;

bool Redundant(string s)
{
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
        {
            st.push(s[i]);
        }
        else if(s[i]==')' && st.size()>=1)
        {
            char a=st.top();
            st.pop();
            if(a=='(')
            {
                return true;
            }
            st.pop();
        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;
    
    cout<<Redundant(s)<<endl;
}