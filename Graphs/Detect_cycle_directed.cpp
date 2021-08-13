/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


*/
#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int> adj[],int s,bool visited[],bool dfsVis[])
{
	    visited[s]=true;
	    dfsVis[s]=true;
	    
	    for(int u:adj[s])
	    {
	        if(visited[u]==false)
	        {
	            if(DFS(adj,u,visited,dfsVis))
	            {
	                return true;
	            }
	        }
	        else if(dfsVis[u]==true)
	        {
	            return true;
	        }
	    }
	    dfsVis[s]=false;
	    return false;
}
	
bool isCyclic(int V, vector<int> adj[]) 
{
	    bool visited[V]={0};
	    bool dfsVis[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(DFS(adj,i,visited,dfsVis))
	            {
	                return true;
	            }
	        }
	    }
	    return false;
}


int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool ans=isCycle(V,adj);
    cout<<ans<<endl;
}