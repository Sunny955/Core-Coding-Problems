/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   

Output: 1
Explanation: 1->2->3->4->1 is a cycle.
Example 2:

Input: 

Output: 0
Explanation: No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
 

Constraints:
1 ≤ V, E ≤ 105
*/
#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int>adj[],int sv,int p,bool visited[])
{
        visited[sv]=true;
        
        for(int u:adj[sv])
        {
            if(visited[u]==false)
            {
                if(DFS(adj,u,sv,visited))
                {
                    return true;
                }
            }
            else
            {
                if(u!=p)
                {
                    return true;
                }
            }
        }
        return false;
}
    
bool isCycle(int V, vector<int>adj[])
{
	    bool visited[V]={0};
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(DFS(adj,i,-1,visited))
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
        adj[v].push_back(u);
    }
    bool ans=isCycle(V,adj);
    cout<<ans<<endl;
}