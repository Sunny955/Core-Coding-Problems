/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
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
        this->left = this->right = NULL;
    }
};

vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root==NULL)
   {
       return ans;
   }
   queue<Node *> Q;
   Q.push(root);
   Q.push(NULL);
   int count=0;
   while(!Q.empty())
   {
       Node *front=Q.front();
        if(front!=NULL)
        {
            Q.pop();
            count++;
            if(count==1)
            {
                ans.push_back(front->data);
            }
        }
        else
        {
            if(Q.size()==1)
            {
                Q.pop();
            }
            else
            {
                Q.pop();
                Q.push(NULL);
                count=0;
            }
            
        }
        
        if(front!=NULL && front->left!=NULL)
        {
            Q.push(front->left);
        }
        if(front!=NULL && front->right!=NULL)
        {
            Q.push(front->right);
        }
   }
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
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    vector<int> ans=leftView(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}