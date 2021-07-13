/*
Implement PreOrder Traversal Iteratively
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

vector<int> rightView(Node *root)
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
           if(front!=NULL && front->right!=NULL)
           {
               Q.push(front->right);
           }
           if(front!=NULL && front->left!=NULL)
           {
               Q.push(front->left);
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
 
    vector<int> ans=rightView(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
 
    return 0;
}