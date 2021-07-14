/*
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.


Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> map;
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

    
string solve(Node *root)
    {
        if(root==NULL)
        {
            return "$";
        }
        string s="";
        if(root->right==NULL && root->left==NULL)
        {
            s=to_string(root->data);
            return s;
        }
        s+=to_string(root->data);
        s+=solve(root->left);
        s+=solve(root->right);
        
        map[s]++;
        return s;
    }
    
    int dupSub(Node *root) 
    {
        map.clear();
        solve(root);
        
        for(auto i:map)
        {
            if(i.second>=2 && i.first.size()>=3)
            {
                return true;
            }
        }
        return false;
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
        4      2       6
              / 
             /   
            4     
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(6);
    root->right->left->left = new Node(4);
 
    cout<<dupSub(root)<<endl;
   
    return 0;
}