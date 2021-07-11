/*
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int CountSmaller(vector<int>& row,int x)
    {
        int l=0,mid,h=row.size()-1;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(row[mid]<=x)
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
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int low=1;
        int high=1e9;
        int n=matrix.size();
        int m=matrix[0].size();
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<n;i++)
            {
                count+=CountSmaller(matrix[i],mid);
            }
            if(count<=(r*c)/2)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }


int main() 
{   
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    
    cout<<median(matrix,n,m)<<endl;
	return 0;
}