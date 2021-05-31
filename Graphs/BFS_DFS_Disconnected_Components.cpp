#include <bits/stdc++.h>
using namespace std;

void print_DFS(int **edges,int n,int sv,bool *visited)
{
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(edges[sv][i]==1 && visited[i]==false)
        {
            print_DFS(edges,n,i,visited);
        }
    }
}

void print_BFS(int **edges,int n,int sv,bool *visited)
{
    queue<int> Q;
    visited[sv]=true;
    Q.push(sv);
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
        cout<<v<<" ";
        for(int i=0;i<n;i++)
        {
            if(edges[v][i]==1 && visited[i]==false)
            {
                Q.push(i);
                visited[i]=true;
            }
        }
    }
}

void BFS(int **edges,int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            print_BFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}

void DFS(int **edges,int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            print_DFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}

int main()
{
    int n,e;
    cin>>n>>e;
    
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        edges[v1][v2]=1;
        edges[v2][v1]=1;
    }
   cout<<"BFS :"<<endl;
   BFS(edges,n);
   cout<<endl;
   cout<<"DFS :"<<endl;
   DFS(edges,n);
}