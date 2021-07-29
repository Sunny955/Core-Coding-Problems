/*
Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.

Examples:  

Input: 
A 12 x 10 matrix with landmines marked as 0

[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]
[ 1  1  1  1  0  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  0  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  0  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 0  1  1  1  1  0  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]

Output:  
Length of shortest safe route is 13 (Highlighted in Bold)
*/

#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
 

int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };
 

bool isSafe(int mat[R][C], int visited[R][C],
            int x, int y)
{
    if (mat[x][y] == 0 || mat[x][y]==-1 || visited[x][y])
        return false;
 
    return true;
}
 

bool isValid(int x, int y)
{
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
 
    return false;
}
 
void markChanges(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
            {
              for (int k = 0; k < 4; k++)
                if (isValid(i + rowNum[k], j + colNum[k]))
                    mat[i + rowNum[k]][j + colNum[k]] = -1;
            }
        }
    }
}
 

void helper(int mat[R][C], int visited[R][C],
                          int i, int j, int &min_dist, int dist)
{
    
    if (j == C-1)
    {
        min_dist = min(dist, min_dist);
        return;
    }
 
    if (dist > min_dist)
        return;
 
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + rowNum[k], j + colNum[k]) &&
            isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
        {
            helper(mat, visited, i + rowNum[k],
                           j + colNum[k], min_dist, dist + 1);
        }
    }
    visited[i][j] = 0;
}
 

int findShortestPath(int mat[R][C])
{
    int min_dist = INT_MAX;

    int visited[R][C];
 
    markChanges(mat);
 
    for (int i = 0; i < R; i++)
    {
     
        if (mat[i][0] == 1)
        {
            
            memset(visited, 0, sizeof visited);
            helper(mat, visited, i, 0,
                                 min_dist, 0);
            if(min_dist == C - 1)
                break;
        }
    }
 
    return min_dist;
}
 
int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
 
    cout<<findShortestPath(mat)<<endl;
 
    return 0;
}