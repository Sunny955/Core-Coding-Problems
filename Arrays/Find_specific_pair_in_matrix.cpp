/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
Example: 

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] 
- mat[1][0] = 18 has maximum difference. 
The program should do only ONE traversal of the matrix. i.e. expected time complexity is O(n2)
*/
#include <bits/stdc++.h>
using namespace std;

int findMaxValue(int n,int** matrix)
{
    int dp[n][n];
    for(int i=0;i<n-1;i++)
    {
        int min_num=INT_MAX;
        for(int j=0;j<n-1;j++)
        {
            if(min_num>matrix[i][j])
            {
                min_num=matrix[i][j];
            }
            dp[i][j]=min_num;
        }
    }
    for(int j=0;j<n-1;j++)
    {
        int min_num=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            if(min_num>dp[i][j])
            {
                min_num=dp[i][j];
            }
            dp[i][j]=min_num;
        }
    }
    int max_diff=INT_MIN;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=n-1;j>=1;j--)
        {
            if(matrix[i][j]-dp[i-1][j-1]>max_diff)
            {
                max_diff=matrix[i][j]-dp[i-1][j-1];
            }
        }
    }
    return max_diff;
}

int main() 
{   
    int n;
    cin>>n;
    int **matrix=new int*[n];
    for(int i=0;i<n;i++)
    {
        matrix[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<findMaxValue(n,matrix)<<endl;
	return 0;
}