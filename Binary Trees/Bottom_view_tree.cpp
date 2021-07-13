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

vector<int> bottomView(Node *root) 
{
        map<int,int> m;
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        queue<pair<Node*,int>> Q;
        Q.push(make_pair(root,0));
        
        while(!Q.empty())
        {
            pair<Node*,int> curr=Q.front();
            Q.pop();
            m[curr.second]=curr.first->data;
            
            if(curr.first->left!=NULL)
            {
                Q.push(make_pair(curr.first->left,curr.second-1));
            }
            if(curr.first->right!=NULL)
            {
                Q.push(make_pair(curr.first->right,curr.second+1));
            }
        }
        auto p=m.begin();
        while(p!=m.end())
        {
            ans.push_back(p->second);
            p++;
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
 
    vector<int> ans=bottomView(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
 
    return 0;
} 