/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
 

Your Task:  
You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.

Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

int Sum(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return root->data+Sum(root->left)+Sum(root->right);
    }
    
    void toSumTree(Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left!=NULL && root->right!=NULL)
        {
            root->data=Sum(root->left)+Sum(root->right);
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            root->data=Sum(root->left);
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            root->data=Sum(root->right);
        }
        else
        {
            root->data=0;
        }
        
        toSumTree(root->left);
        toSumTree(root->right);
    }

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
   
    toSumTree(root);
    cout<<root->data<<" ";
    cout<<root->left<<" ";
    cout<<root->right<<" ";
 
    return 0;
} 