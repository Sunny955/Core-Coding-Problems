/*
Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail
Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the 
optimal choice.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maximumSumRectangle() which takes the number R, C, and the 2D matrix M as input parameters and returns the maximum sum subarray.


Expected Time Complexity:O(R*R*C)
Expected Auxillary Space:O(R*C)
*/

#include<bits/stdc++.h>
using namespace std;

int Kadane(vector<int>& v,int n)
    {
        int dp[n];
        dp[0]=v[0];
        int max_sum=v[0];
        for(int i=1;i<n;i++)
        {
            if(v[i]+dp[i-1]>v[i])
            {
                dp[i]=v[i]+dp[i-1];
            }
            else
            {
                dp[i]=v[i];
            }
            
            if(dp[i]>max_sum)
            {
                max_sum=dp[i];
            }
        }
        return max_sum;
    }
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        int curr_sum=M[0][0];
        int max_sum=INT_MIN;
        for(int L=0;L<R;L++)
        {
            vector<int> col(C,0);
            for(int r=L;r<R;r++)
            {
               for(int j=0;j<C;j++)
               {
                   col[j]+=M[r][j];
               }
               curr_sum=Kadane(col,C);
               if(curr_sum>max_sum)
               {
                   max_sum=curr_sum;
               }
            }
        }
        return max_sum;
    }
    
int main()
{
    int R,C,a;
    cin>>R>>C;
    
    vector<vector<int>> M(R,vector<int>(C,0));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>a;
            M[i][j]=a;
        }
    }
    cout<<maximumSumRectangle(R,C,M)<<endl;
}