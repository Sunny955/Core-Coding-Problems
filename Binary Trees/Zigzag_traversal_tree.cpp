#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	if(root==NULL)
	{
	    return ans;
	}
	queue<Node *> Q;
	Q.push(root);
	Q.push(NULL);
	stack<Node *> S;
	int count=0;
	while(!Q.empty())
	{
	    Node *front=Q.front();
	    
	    if(front!=NULL)
	    {
	        if(count%2==0)
	        {
	            ans.push_back(front->data);
	        }
	        else
	        {
	            ans.push_back(S.top()->data);
	            S.pop();
	        }
	        Q.pop();
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
	            count++;
	        }
	    }
	    
	    if(count%2==0)
	    {
	        if(front!=NULL && front->left!=NULL)
	        {
	            S.push(front->left);
	        }
	        if(front!=NULL && front->right!=NULL)
	        {
	            S.push(front->right);
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
 
    vector<int> ans=zigZagTraversal(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
 
    return 0;
} 