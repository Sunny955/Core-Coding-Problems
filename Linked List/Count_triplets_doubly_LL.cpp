/*
Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.

Examples:
 
DDL : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
x=17

Output:2
The triplets are: (2,6,9) and (4,5,8)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node* next, *prev;
};


int countTriplets(Node *head,int x)
{
    unordered_map<int,Node*> map;
    Node *ptr,*ptr1,*ptr2;
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        map[ptr->data]=ptr;
    }
    int count=0;
    for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
        {
            int p_sum=ptr1->data+ptr2->data;
            
            if(map.find(x-p_sum)!=map.end() && map[x-p_sum]!=ptr1 && map[x-p_sum]!=ptr2)
            {
                count++;
            }
        }
    }
    return (count/3);
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
 
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
 
    int x = 17;
 
    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}

