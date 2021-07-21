/*
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.

Examples:

Input : BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
Output : 3
The pairs are:
(5, 11), (6, 10) and (8, 8)
Input:
The function takes three arguments as input, first the reference pointer to the root(root1) of the BST1, then reference pointer to the root(root2) of the BST2 and last the element X.

Output:
For each input return the required number of pairs on new line.

Constraints:
1<=N<=103
*/
#include<bits/stdc++.h>
using namespace std;

bool Search(Node *root,int key)
{
    if(root==NULL)
    {
        return false;
    }
    
    if(root->data==key)
    {
        return true;
    }
    
    if(root->data<key)
    {
        Search(root->right,key);
    }
    else
    {
        Search(root->left,key);
    }
}

void Count(Node* root1,Node* root2,int x,int& ans)
{
    if(root1==NULL)
    {
        return;
    }
    if(Search(root2,x-root1->data))
    {
        ans++;
    }
    Count(root1->left,root2,x,ans);
    Count(root1->right,root2,x,ans);
}

int countPairs(Node* root1, Node* root2, int x)
{
    int ans=0;
    Count(root1,root2,x,ans);
    return ans;
}
