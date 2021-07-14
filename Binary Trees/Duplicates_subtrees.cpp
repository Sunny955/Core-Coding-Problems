/*
Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Example:

Input : 

Output : 2 4
         4
Explanation: Above Trees are two 
duplicate subtrees.i.e  and 
Therefore,you need to return above trees 
root in the form of a list.
Your Task:
You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.
Note: Here the Output of every Node printed in the Pre-Order tree traversal format.


Constraints:
1<=T<=100
1<=N<=100
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

unordered_map<string,int> m;

string solve(Node* root,vector<node*> &ans)
{
    if(root == NULL)
    {
        return "$";
    }
    string s = to_string(root->data);
    s = s + " " + solve(root->right,ans)+ " " + solve(root->left,ans);
    m[s] = m[s] + 1;
    if(m[s]==2)
    ans.push_back(root);
    return s;
}

vector<node*> printAllDups(Node* root)
{
    m.clear();
    vector<node*> ans;
    string s = solve(root,ans);
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