#include<bits/stdc++.h>
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

int LongestPlain(string input)
{
    string str1=input;
    reverse(input.begin(),input.end());
    string str2=input;
    
    int x=str1.size();
    int y=str2.size();
    
    return lcsIter(x,y,str1,str2);
    
}

int main()
{
    string input;
    cin>>input;
    
    cout<<LongestPlain(input)<<endl;
}