/*
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
â€‹Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.


Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1 ≤ N ≤ 100
1 ≤ Matrix[i][j] ≤ 1000
*/

#include<bits/stdc++.h>
using namespace std;

int maximumPath(int N, vector<vector<int>> Matrix)
{
    // code here
        
    int **dp=new int*[N];
        
    for(int i=0;i<N;i++)
    {
        dp[i]=new int[N];
        for(int j=0;j<N;j++)
        {
            dp[i][j]=0;
        }
    }
        
        
    for(int j=0;j<N;j++)
    {
        dp[0][j]+=Matrix[0][j];
    }
    int max_sum=INT_MIN;
        
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(j>0 && j<N-1)
            {
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
            }
            else if(j==0)
            {
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
            }
            else if(j==N-1)
            {
                    dp[i][j]=Matrix[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
        
    for(int j=0;j<N;j++)
    {
        if(max_sum<dp[N-1][j])
        {
            max_sum=dp[N-1][j];
        }
    }
       return max_sum;
}

int main()
{
    int N,a;
    cin>>N;
    vector<vector<int>> Matrix(N,vector<int>(N,0));
    vector<int> input;
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++)
        {
           cin>>a;
           input.push_back(a);
        }
        Matrix.push_back(input);
        input.clear();
    }
    cout<<maximumPath(N,Matrix)<<endl;
}

