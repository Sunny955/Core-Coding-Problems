/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
void MarkNum(vector<vector<int>>& grid,int x,int y,int& count1)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(x-1>=0 && y>=0 && y<m && grid[x-1][y]==1)
        {
            grid[x-1][y]=2;
            count1--;
        }
        if(x+1<n && y>=0 && y<m && grid[x+1][y]==1)
        {
            grid[x+1][y]=2;
            count1--;
        }
        if(x>=0 && x<n && y-1>=0 && grid[x][y-1]==1)
        {
            grid[x][y-1]=2;
            count1--;
        }
        if(x>=0 && x<n && y+1<m && grid[x][y+1]==1)
        {
            grid[x][y+1]=2;
            count1--;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int count1=0;
        int ans=0;
        
        queue<pair<int,int>> Q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count1++;
                }
                if(grid[i][j]==2)
                {
                    Q.push(make_pair(i,j));
                    grid[i][j]=-1;
                }
            }
        }
        if(Q.empty())
        {
            return -1;
        }
        
        int prev=count1;
        while(!Q.empty())
        {
            int x=Q.front().first;
            int y=Q.front().second;
            Q.pop();
            MarkNum(grid,x,y,count1);
        }
        if(count1==0)
        {
            return 1;
        }
        else if(prev>count1 && count1!=0)
        {
            ans++;
        }
        else
        {
            return -1;
        }
        
        while(prev>count1)
        {
            prev=count1;
            
             for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    if(grid[i][j]==2)
                    {
                        Q.push(make_pair(i,j));
                        grid[i][j]=-1;
                    }
                }
            }
            while(!Q.empty())
            {
                int x=Q.front().first;
                int y=Q.front().second;
                Q.pop();
                MarkNum(grid,x,y,count1);
            }
            
            if(prev>count1)
            {
                ans++;
            }
        }
        if(count1==0)
        {
            return ans;
        }
        return -1;
        
    }
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> grid(n,vector<int>(m,0)) ;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<orangesRotting(grid)<<endl;
}