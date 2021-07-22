/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/
#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& m,int n,vector<string>& temp,int x,int y,string s)
{
        if(x<0 || y<0 || x>=n || y>=n || m[x][y]!=1)
        {
            return;
        }
        if(x==n-1 && y==n-1)
        {
            temp.push_back(s);
            return;
        }
        
        m[x][y]=-1;
        helper(m,n,temp,x+1,y,s+'D');
        helper(m,n,temp,x,y-1,s+'L');
        helper(m,n,temp,x,y+1,s+'R');
        helper(m,n,temp,x-1,y,s+'U');
       
        m[x][y]=1;
}
    
vector<string> findPath(vector<vector<int>> &m, int n) 
{
        vector<string> temp;
        string s="";
        helper(m,n,temp,0,0,s);
        return temp;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>m(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }
    vector<string> ans=findPath(m,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}