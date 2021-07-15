/*
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.
*/
#include <bits/stdc++.h>
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

void Order(Node *root,unordered_map<int,int>& map,int dis)
    {
        
        
        if(root->left==NULL && root->right==NULL)
        {
            map[abs(dis)]=root->data;
            return;
        }
       
        if(root->left!=NULL)
        {
            Order(root->left,map,dis+1);
        }
        if(root->right!=NULL)
        {
            Order(root->right,map,dis+1);
        }
        
    }
    
    bool check(Node *root)
    {
        if(root==NULL)
        {
            return true;
        }
        
        unordered_map<int,int> map;
        Order(root,map,0);
        
        if(map.size()==1)
        {
            return true;
        }
        return false;
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
 
    cout<<check(root)<<endl;
 
    return 0;
}
