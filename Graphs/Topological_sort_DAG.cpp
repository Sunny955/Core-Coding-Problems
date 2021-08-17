/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:


Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 2, 1, 3, 4, 0.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


*/


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],int sv,vector<bool>& visited,stack<int>& st)
{
	    visited[sv]=true;
	    for(int i=0;i<adj[sv].size();i++)
	    {
	        if(!visited[adj[sv][i]])
	        {
	            dfs(adj,adj[sv][i],visited,st);
	        }
	    }
	    st.push(sv);
}
	
vector<int> topoSort(int V, vector<int> adj[]) 
{
	   vector<int> ans;
	   stack<int> st;
	   vector<bool> visited(V,false);
	   
	   for(int i=0;i<V;i++)
	   {
	       if(!visited[i])
	       {
	           dfs(adj,i,visited,st);
	       }
	   }
	   
	   while(!st.empty())
	   {
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
}

int main()
{
    int V,E;
    cin>>V>>E;
    
    vector<int> adj[V];
    for(int i=0;i<V;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> ans=topoSort(V,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
}