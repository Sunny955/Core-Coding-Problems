/*
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:

Input:
      2
    /   \
   1     3
K = 2
Output: 2
Example 2:

Input:
        2
      /  \
     1    3
K = 5
Output: -1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/
#include<bits/stdc++.h>
using namespace std;

int ans=-1;
void Trav(Node *root,int& K)
{
    if(root==NULL)
    {
        return;
    }
    Trav(root->left,K);
    K=K-1;
    if(K==0)
    {
        ans=root->data;
    }
    Trav(root->right,K);
}
    
int KthSmallestElement(Node *root, int K)
{
    ans=-1;
    Trav(root,K);
    return ans;
}