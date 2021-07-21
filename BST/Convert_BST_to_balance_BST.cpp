/*
Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
Examples : 

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 
*/
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* left,  *right;
};


Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void Inorder(Node* root,vector<Node *>& path)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left,path);
    path.push_back(root);
    Inorder(root->right,path);
}

Node *buildTreeUtil(vector<Node*>& path,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    
    int mid=low+(high-low)/2;
    Node *root=path[mid];
    
    root->left=buildTreeUtil(path,low,mid-1);
    root->right=buildTreeUtil(path,mid+1,high);
    
    return root;
}

Node* buildTree(Node* root)
{
    vector<Node *> path;
    Inorder(root,path);
    int n=path.size();
    return buildTreeUtil(path,0,n-1);
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
 
    root = buildTree(root);
 
    printf("Preorder traversal of balanced "
            "BST is : \n");
    preOrder(root);
 
    return 0;
}