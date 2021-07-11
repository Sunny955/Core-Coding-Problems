/*
searching in column and row sorted matrix
{10 20 30 40}
{12 25 35 45}
{27 29 37 48}
{32 33 39 50}

search 29
29 is at (2,1)

If element isn't present return -1
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> Search(int **matrix,int n,int x)
{
    vector<int> ans(2,-1);
    int i=0,j=n-1;
    while(i<n && j>=0)
    {
        if(matrix[i][j]==x)
        {
            ans[0]=i;
            ans[1]=j;
            break;
        }
        else if(matrix[i][j]>x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

int main() 
{   
    int n,x;
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
    cin>>x;
    vector<int> ans=Search(matrix,n,x);
    cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}