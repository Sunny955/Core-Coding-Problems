/*
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 105

*/
#include<bits/stdc++.h>
using namespace std;

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL)
    {
        return NULL;
    }
        
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
        
    Node *left=lca(root->left,n1,n2);
    Node *right=lca(root->right,n1,n2);
        
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    return left!=NULL ? left:right;
}
    
int dis(Node *root,int val,int d)
{
    if(root==NULL)
    {
        return 1086543;
    }
    if(root->data==val)
    {
        return d;
    }
    int l=dis(root->left,val,d+1);
    int r=dis(root->right,val,d+1);
    return min(l,r);
}

int findDist(Node* root, int a, int b) 
{
    Node* anc=lca(root,a,b);
    
    int l=dis(anc,a,0);
    int r=dis(anc,b,0);
    return l+r;
}
