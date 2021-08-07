/*
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
 

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes grid as input parameter and returns a matrix of same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid)
{
	    vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),INT_MAX));
	    
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    queue<pair<int,int>> Q;
	    
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[i].size();j++)
	        {
	            if(grid[i][j]==1)
	            {
	                Q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    vector<pair<int,int>> store = {{0,1},{1,0},{0,-1},{-1,0}};
	    while(!Q.empty())
	    {
	        int x1=Q.front().first;
	        int y1=Q.front().second;
	        Q.pop();
	        
	        for(auto i:store)
	        {
	            int x2=x1+i.first;
	            int y2=y1+i.second;
	            
	            if(x2>=0 && x2<n && y2>=0 && y2<m)
	            {
	                if(ans[x2][y2]>ans[x1][y1]+1)
	                {
	                    ans[x2][y2]=ans[x1][y1]+1;
	                    Q.push({x2,y2});
	                }
	            }
	        }
	    }
	    return ans;
	    
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
       {
           cin>>grid[i][j];
       }
    }
    
    vector<vector<int>> ans=nearest(grid);
    
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}