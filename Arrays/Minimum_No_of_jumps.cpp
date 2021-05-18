/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Example 1:

Input:
N=11 
arr=1 3 5 8 9 2 6 7 6 8 9 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
Example 2:

Input :
N= 6
arr= 1 4 3 2 6 7
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.
Your task:
You don't need to read input or print anything. Your task is to complete function minJumps() which takes the array arr and it's size N as input parameters and returns the minimum number of jumps.

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)

Constraints:
1 ≤ N ≤ 107
0 <= ai <= 107
*/

#include<bits/stdc++.h>
using namespace std;

 int minJumps(int arr[], int n)
{
    int jumps=0,curr_max=0,curr_end=0;
        
    for(int i=0;i<n-1;i++)
    {
        curr_max=max(curr_max,i+arr[i]);
        if(i==curr_end)
        {
            jumps++;
            curr_end=curr_max;
        }
            
        if(curr_end>=n-1)
        {
            break;
        }
    }    
        
    if(curr_end<n-1)
    {
        return -1;
    }
    return jumps;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minJumps(arr,n);
    return 0;
}