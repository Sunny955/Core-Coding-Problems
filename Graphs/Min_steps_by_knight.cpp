/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

 

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/
#include<bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
	    queue<pair<int,int>> q;
	    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
	    
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<int> x_move={2,2,-2,-2,1,1,-1,-1};
	    vector<int> y_move={1,-1,1,-1,2,-2,2,-2};
	    
	    int xx,yy;
	    int moves=0;
	    visited[q.front().first][q.front().second]=true;
	    while(!q.empty())
	    {
	       int n=q.size();
	       for(int i=0;i<n;i++)
	       {
	           pair<int,int> coord=q.front();
	           q.pop();
	           if(coord.first==TargetPos[0] && coord.second==TargetPos[1])
	           {
	               return moves;
	           }
	           for(int i=0;i<8;i++)
	           {
	               xx=coord.first+x_move[i];
	               yy=coord.second+y_move[i];
	               if(xx>=1 && xx<=N && yy>=1 && yy<=N && visited[xx][yy]==false)
	               {
	                   visited[xx][yy]=true;
	                   q.push({xx,yy});
	               }
	           }
	       }
	       moves++;
	    }
	    return -1;
}

int main()
{
    int N;
    cin>>N;
    
    vector<int> KnightPos(2,0);
    vector<int> TargetPos(2,0);
    
    for(int i=0;i<2;i++)
    {
        cin>>KnightPos[i];
    }
    for(int i=0;i<2;i++)
    {
        cin>>TargetPos[i];
    }
    
    cout<<minStepToReachTarget(KnightPos,TargetPos,N)<<endl;
    return 0;
}