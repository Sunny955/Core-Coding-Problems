/*
Given a binary tree with distinct nodes(no two nodes have the same have data values). The problem is to print the path from root to a given node x. If node x is not present then print “No Path”.

Examples: 

Input :          1
               /   \
              2     3
             / \   /  \
            4   5  6   7

               x = 5

Output : 1->2->5
*/
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

bool find_path(Node *root,vector<int>& path,int key)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root->data);
   
    if(root->data==key)
    {
       return true;
    }
    
    if(find_path(root->left,path,key) || find_path(root->right,path,key))
    {
        return true;
    }
    
    path.pop_back();
    return false;
   
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right=new Node(10);
    root->right->right->left=new Node(12);
    
    vector<int> path;
    int key;
    cin>>key;
    find_path(root,path,key);
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    return 0;
}