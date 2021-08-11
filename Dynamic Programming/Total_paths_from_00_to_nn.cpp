/*
Total number of paths from 0,0 to n-1,m-1 in a matrix of n*m 
*/
#include<bits/stdc++.h>
using namespace std;

void Paths(vector<vector<int>>& mat,int x,int y,int n,int m,int& count)
{
    if(x==n-1 && y==m-1)
    {
        int mod=1e9+7;
        count=count%mod;
        count++;
        return;
    }
    
    int temp=mat[x][y];
    mat[x][y]=-1;
    
    if(x+1<n && y>=0 && y<m && mat[x+1][y]==1)
    {
        Paths(mat,x+1,y,n,m,count);
    }
    if(x>=0 && x<n && y+1<m && mat[x][y+1]==1)
    {
        Paths(mat,x,y+1,n,m,count);
    }
    mat[x][y]=temp;
    return;
}

int Count(vector<vector<int>>& mat,int n,int m,int x,int y,int **dp)
{
    dp[0][0]=1;
    for(int i=1;i<m;i++)
    {
        if(mat[0][i]!=0)
        {
            if(dp[0][i-1]!=0)
            {
                dp[0][i]=1;
            }
            else
            {
                dp[0][i]=0;
            }
        }
        else
        {
            dp[0][i]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(mat[i][0]!=0)
        {
            if(dp[i-1][0]!=0)
            {
                dp[i][0]=1;
            }
            else
            {
                dp[i][0]=0;
            }
        }
        else
        {
            dp[i][0]=0;
        }
    }
    int mod=1e9+7;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-1]%mod)%mod);
        }
    }
    return dp[n-1][m-1];
}

int CountPaths(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    int count=0;
    // Paths(mat,0,0,n,m,count);
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
        }
    }
    return Count(mat,n,m,0,0,dp);
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<CountPaths(mat)<<endl;
}