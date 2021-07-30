/*
Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list. 
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.
 Input:  3 <-> 6 <-> 2 <-> 12 <-> 56 <-> 8
         K=2
         
 Output: 2 <-> 3 <-> 6 <-> 8 <-> 12 <-> 56
  
*/

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* next, *prev;
};

struct compare
{
    bool operator()(Node* p1,Node* p2)
    {
        return p1->data > p2->data;
    }
};

Node* KSortedDLL(Node* head,int k)
{
    priority_queue<Node*, vector<Node*>, compare> pq;
    struct Node* newNode=NULL,*tail;
    
    Node *p=head;
    int i=0;
    while(p!=NULL && i<=k)
    {
        pq.push(head);
        p=p->next;
        i++;
    }
    
    while(!pq.empty())
    {
        if(newNode==NULL)
        {
            newNode=pq.top();
            newNode->prev=NULL;
            tail=newNode;
        }
        else
        {
            tail->next=pq.top();
            pq.top()->prev=tail;
            tail=pq.top();
        }
        pq.pop();
        
        if(p!=NULL)
        {
            pq.push(p);
            p=p->next;
        }
    }
    tail->next=NULL;
    return newNode;
}

void print(Node* head)
{
    Node* p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void insert(struct Node** head, int data)
{
    struct Node* temp = new Node();
 
    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 


int main()
{
    struct Node* head = NULL;
 

    insert(&head, 8);
    insert(&head, 56);
    insert(&head, 12);
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 3);
 
    Node *newNode=KSortedDLL(head,2);
    print(newNode);
    
    return 0;
}

