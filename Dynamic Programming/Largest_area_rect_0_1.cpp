/*
Given a binary matrix. The problem is to find the largest area rectangular sub-matrix with equal number of 1’s and 0’s.

Examples:

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 1} }
Output : 8 sq. units
(Top, left): (0, 0)
(Bottom, right): (3, 1)

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 1} }            
Output : 6 sq. units
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> SubbSumZero(vector<int>& row,int n)
{
    unordered_map<int,int>map;
    vector<int>sum(n,0);
     sum[0] = row[0];
    for (int i=1; i<n; i++)
    {   
        sum[i] = sum[i-1] + row[i]; 
    }
    vector<int> ans(2,-1);
    int max_len=0;
    for(int j=0;j<n;j++)
    {
        if(sum[j]==0)
        {
            ans[0]=0;
            ans[1]=j;
            max_len=j+1;
        }
        
        if(map.find(sum[j])!=map.end())
        {
            if(max_len<j-map[sum[j]])
            {
                max_len=j-map[sum[j]];
                ans[0]=map[sum[j]]+1;
                ans[1]=j;
            }
        }
        else
        {
            map[sum[j]]=j;
        }
        
    }
    return ans;
}

int MaxAreaRact(int **Matrix,int r,int c,vector<int>& coord)
{
    int max_area=0;
    int left_fin=-1,right_fin=-1,top_fin=-1,bottom_fin=-1; 
    
    for(int L=0;L<c;L++)
    {
        vector<int> row(r,0);
        for(int R=L;R<c;R++)
        {
            for(int i=0;i<r;i++)
            {
                row[i]+=Matrix[i][R] ? 1:-1;
            }
            
            vector<int> up_down=SubbSumZero(row,r);
            if(up_down[0]>-1 && up_down[1]>-1)
            {
                int area=(up_down[1]-up_down[0]+1)*(R-L+1);
                if(area>max_area)
                {
                    max_area=area;
                    left_fin=L;
                    right_fin=R;
                    top_fin=up_down[0];
                    bottom_fin=up_down[1];
                }
            }
        }
    }
    coord[0]=left_fin;
    coord[1]=right_fin;
    coord[2]=top_fin;
    coord[3]=bottom_fin;
    
    return max_area;
}

int main()
{
    int R,C;
    cin>>R>>C;
    
    int **Matrix=new int*[R];
    
    for(int i=0;i<R;i++)
    {
        Matrix[i]=new int[C];
    }
    
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>Matrix[i][j];
        }
    }
    vector<int> coord(4,0);
    cout<<MaxAreaRact(Matrix,R,C,coord)<<endl;
    
    cout<<"left "<<coord[0]<<" right "<<coord[1]<<" top "<<coord[2]<<" bottom "<<coord[3]<<endl;

    
}