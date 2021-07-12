/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)
*/
#include<bits/stdc++.h>
using namespace std;
# define MAX 1000
int mat[MAX][MAX];

int CountLessThan(int mat[MAX][MAX],int row,int x,int n)
{
    int l=0,mid,h=n-1;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(mat[row][mid]<=x)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return l;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low=mat[0][0];
    int high=mat[n-1][n-1];
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            count+=CountLessThan(mat,i,mid,n);
        }
    
        if(count<k)
        {
            low=mid+1;        
        }
        else
        {
            high=mid-1;
        }
    }
    int num=low;
    int i=0,j=n-1;
    while(i<n && j>=0)
    {
        if(mat[i][j]==num)
        {
            break;
        }
        else if(mat[i][j]>num)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    low=mat[i][j];
    return low;

}


int main()
{
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cin>>k;
    cout<<kthSmallest(mat,n,k)<<endl;
}