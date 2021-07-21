/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.


Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).


*/
#include<bits/stdc++.h>
using namespace std;

void Inorder(Node* root,vector<int>& path)
    {
        if(root==NULL)
        {
            return;
        }
        Inorder(root->left,path);
        path.push_back(root->data);
        Inorder(root->right,path);
    }
    
    void Change(Node *root,vector<int>& path,int &i)
    {
        if(root==NULL)
        {
            return;
        }
        Change(root->left,path,i);
        root->data=path[i++];
        Change(root->right,path,i);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> path;
        Inorder(root,path);
        sort(path.begin(),path.end());
        int i=0;
        Change(root,path,i);
        return root;
    }