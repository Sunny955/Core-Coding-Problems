/*
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples : 

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
*/
#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

bool isSafe(int x,int y,vector<vector<int>>& grid,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!=-1)
    {
        return true;
    }
    return false;
}

void FindPaths(vector<vector<int>>& grid,int x,int y,int n,int m,vector<int>& ans)
{
    if(x==n-1 && y==m-1)
    {
        ans.push_back(grid[x][y]);
        display(ans);
        ans.pop_back();
        return;
    }
    
    int temp=grid[x][y];
    ans.push_back(temp);
    grid[x][y]=-1;
    
    if(isSafe(x+1,y,grid,n,m))
    {
        FindPaths(grid,x+1,y,n,m,ans);
    }
    if(isSafe(x,y+1,grid,n,m))
    {
        FindPaths(grid,x,y+1,n,m,ans);
    }
    
    grid[x][y]=temp;
    ans.pop_back();
    return;
    
}

int main() 
{
      int n = 3 ,m =3;
      vector<vector<int> >grid{ {1,2,3},{4,5,6},{7,8,9}};
      vector<int>ans ; 
       
      FindPaths(grid,0,0,n,m,ans); 
    return 0;
}