/*
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

 

Example 1:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree
is mirror image of the first.
Example 2:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree
isn't mirror image of the first.
*/

#include<bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[]) 
    {
        vector<stack<int>> s(n+1);
        vector<queue<int>> q(n+1);
        
        for(int i=0;i<2*e;i+=2)
        {
            s[A[i]].push(A[i+1]);
            q[B[i]].push(B[i+1]);
        }
        
        for(int i=1;i<=n;i++)
        {
            while(!s[i].empty() && !q[i].empty())
            {
                int a=s[i].top();
                int b=q[i].front();
                
                if(a!=b)
                {
                    return false;
                }
                s[i].pop();
                q[i].pop();
            }
        }
        return true;
    }    

