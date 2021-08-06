/*
A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue to the output queue with the help of a stack and the built-in push and pop functions.

The well defined rules are:

Only dequeue from the input queue.
Use inbuilt push, pop functions in the single stack.
Stack and input queue must be empty at the end.
Only enqueue to the output queue.
There are a huge number of permutations possible using a stack for a single input queue.
Given two arrays, both of unique elements. One represents the input queue and the other represents the output queue. Our task is to check if the given output is possible through stack permutation.

Examples:

Input : First array: 1, 2, 3  
        Second array: 2, 1, 3
Output : Yes
Procedure:
push 1 from input to stack
push 2 from input to stack
pop 2 from stack to output
pop 1 from stack to output
push 3 from input to stack
pop 3 from stack to output


Input : First array: 1, 2, 3  
        Second array: 3, 1, 2
Output : Not Possible  
*/
#include<bits/stdc++.h>
using namespace std;

bool checkStackPermutation(int input[], int output[], int n)
{
    queue<int> in;
    queue<int> out;
    
    for(int i=0;i<n;i++)
    {
        in.push(input[i]);
        out.push(output[i]);
    }
    stack<int> st;
    while(!in.empty())
    {
        int a=in.front();
        in.pop();
        
        if(a==out.front())
        {
            out.pop();
            
            while(!st.empty() && st.top()==out.front())
            {
                st.pop();
                out.pop();
            }
            
        }
        else
        {
            st.push(a);
        }
    }
    
    if(in.empty() && st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    
    int input[] = {1, 2, 3};
    int output[] = {2, 1, 3};
 
    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
