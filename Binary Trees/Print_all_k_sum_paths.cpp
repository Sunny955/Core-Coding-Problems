/*
A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.
Examples: 
 

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void printPath(vector<int> &path,int i)
{
    for(int j=i;j<path.size();j++)
    {
        cout<<path[j]<<" ";
    }
    cout<<endl;
}

void printKPathUtil(Node *root,vector<int>& path,int k)
{
    if(root==NULL)
    {
        return;
    }
    
    path.push_back(root->data);
    
    printKPathUtil(root->left,path,k);
    
    printKPathUtil(root->right,path,k);
    
    int f=0;
    for(int i=path.size()-1;i>=0;i--)
    {
        f+=path[i];
        
        if(f==k)
        {
            printPath(path,i);
        }
    }
    path.pop_back();
}

void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    int k = 5;
    printKPath(root, k);
 
    return 0;
}