/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> func(Node *root)
{
    if(root==NULL)
    {
        return {1,0,INT_MAX,0};
    }
    vector<int> a=func(root->left);
    vector<int> b=func(root->right);
    
    if(a[0]==1 && b[0]==1 && root->data>a[3] && root->data<b[2])
    {
        return {1,a[1]+b[1]+1,min(root->data,min(a[2],b[2])),max(root->data,max(a[3],b[3]))};
    }
    else
    {
        return {0,max(a[1],b[1]),0,0};
    }
}
int largestBst(Node *root)
{
    vector<int> ans=func(root);
    return ans[1];
}