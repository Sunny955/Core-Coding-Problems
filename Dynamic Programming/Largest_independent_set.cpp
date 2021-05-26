/*

Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset. 
For example, consider the following binary tree. The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.
*/

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    int liss;
    node *left, *right;
};
 
 
int LISS(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    if(root->liss)
    {
        return root->liss;
    }
    
    int excl=LISS(root->left)+LISS(root->right);
    int incl=1;
    if(root->left!=NULL)
    {
        incl+=LISS(root->left->left)+LISS(root->left->right);
    }
    
    if(root->right!=NULL)
    {
        incl+=LISS(root->right->left)+LISS(root->right->right);
    }
    root->liss=max(excl,incl);
    
    return max(excl,incl);
}

node* newNode( int data )
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    cout << "Size of the Largest"
         << " Independent Set is "
         << LISS(root);
 
    return 0;
}