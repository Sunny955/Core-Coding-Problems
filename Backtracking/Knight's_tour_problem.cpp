/*
Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.

Example:

Input : 
N = 8
Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12
*/

#include <bits/stdc++.h>
using namespace std;
#define N 8

bool isSafe(int sol[N][N],int x,int y)
{
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

void printSol(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

int solve(int x,int y,int move,int sol[N][N],int x_dir[N],int y_dir[N])
{
    
    int next_x,next_y;
    if(move==N*N)
    {
        return 1;
    }
    
    for(int i=0;i<N;i++)
    {
        next_x=x+x_dir[i];
        next_y=y+y_dir[i];
        
        if(isSafe(sol,next_x,next_y))
        {
            sol[next_x][next_y]=move;
            if(solve(next_x,next_y,move+1,sol,x_dir,y_dir)==1)
            {
                return 1;
            }
            else
            {
                sol[next_x][next_y]=-1;
            }
        }
    }
    return 0;
}

int main()
{
    int sol[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            sol[i][j]=-1;
        }
    }
    int x_dir[8]={2, 1, -1, -2, -2, -1, 1, 2};
    int y_dir[8]={1, 2, 2, 1, -1, -2, -2, -1};
    sol[0][0]=0;
    
    if(solve(0,0,1,sol,x_dir,y_dir)==0)
    {
        cout<<"No Solution"<<endl;
    }
    else
    {
        printSol(sol);
    }
    
}