/*
Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

Examples: 

Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

Input:
1 2
3 4
Output:
3 1
4 2 
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(int **matrix,int n)
{
    vector<int> temp;
    for(int j=0;j<n;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            temp.push_back(matrix[i][j]);
        }
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=temp[k];
            k++;
        }
    }
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
    rotate(matrix,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}