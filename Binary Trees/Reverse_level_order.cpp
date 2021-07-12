/*
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

Your Task: 
You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
     queue<Node*> Queue; Queue.push(root);
     stack<int> Stack;

    while(!Queue.empty())
    {
        Node* Current_Node = Queue.front();
        Queue.pop();
        Stack.push(Current_Node->data);

        if(Current_Node->right!=NULL) Queue.push(Current_Node->right);
        if(Current_Node->left!=NULL) Queue.push(Current_Node->left);
    }

    while(!Stack.empty())
    {
        ans.push_back(Stack.top());
        Stack.pop();
    }
    return ans;
}
