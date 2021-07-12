/*
Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

Examples: 

Input:
        5
       / \
      3   6
     / \
    2   4
Output:
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2
Mirror tree will be:
  5
 / \
6   3
   / \
  4   2

Input:
        2
       / \
      1   8
     /     \
    12      9
Output:
Inorder of original tree: 12 1 2 8 9 
Inorder of mirror tree: 9 8 2 1 12

struct Node 
{
    int val;
    struct Node* left;
    struct Node* right;
};
*/

#include<bits/stdc++.h>
using namespace std;


void MirrorBinary(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        Node *temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    if(root->left==NULL && root->right!=NULL)
    {
        root->left=root->right;
        root->right=NULL;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        root->right=root->left;
        root->left=NULL;
    }
    
    MirrorBinary(root->left);
    MirrorBinary(root->right);
}