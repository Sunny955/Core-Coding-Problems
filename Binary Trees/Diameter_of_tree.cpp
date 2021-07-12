/*
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/

#include <bits/stdc++.h>
using namespace std;

int height(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
        
    return 1+max(height(root->left),height(root->right));
}

int diameter(Node* root) 
{
    if(root==NULL)
    {
        return 0;
    }
    int op1=1+height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);
        
    return max(op1,max(op2,op3));
}
