/*
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/
#include <bits/stdc++.h>
using namespace std;

bool Rotation(string a,string b)
{
    string temp=a+a;
    int i,n;
    n=temp.size();
    if(a.size()!=b.size())
    {
        return false;
    }
    for(i=0;i<temp.size();i++)
    {
        if(temp[i]==b[0])
        {
            break;
        }
    }
    
    int j=0;
    if(n-i>=b.size())
    {
        while(b[j]==temp[i])
        {
            j++;
            i++;
        }
        
    }
    
    if(j==b.size())
    {
        return true;
    }
    return false;
    
}

int main() 
{
    string a,b;
    cin>>a>>b;
    bool ans=Rotation(a,b);
    cout<<ans<<endl;
}