/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<Node *> Q;
        Q.push(root);
        while(Q.size()!=0)
        {
            Node* front=Q.front();
            Q.pop();
            ans.push_back(front->data);
            
            if(front->left!=NULL)
            {
                Q.push(front->left);
            }
            if(front->right!=NULL)
            {
                Q.push(front->right);
            }
            
        }
        return ans;
    }
