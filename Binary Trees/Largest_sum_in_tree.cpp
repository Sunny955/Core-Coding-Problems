/*
Given a binary tree, task is to find subtree with maximum sum in tree.
Examples: 
 

Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output : 28
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Input :       1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output : 7
Subtree with largest sum is :  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.
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

int sum_subtree(Node *root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    int out=root->data+sum_subtree(root->left,ans)+sum_subtree(root->right,ans);
    
    ans=max(out,ans);
    return out;
}

int max_sum_subtree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int ans=INT_MIN;
    sum_subtree(root,ans);
    return ans;
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
   
    cout<<max_sum_subtree(root)<<endl;
 
    return 0;
} 