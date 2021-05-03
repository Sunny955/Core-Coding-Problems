
/* Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
*/


#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[],int n)
{
    unordered_map<int,int> map;
    int curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum==0)
        {
            return true;
        }
        if(map.find(curr_sum)!=map.end())
        {
            return true;    
        }
        else
        {
            map[curr_sum]=1;
        }
    }
    return false;
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
    bool ans=subArrayExists(arr,n);
    cout<<ans<<endl;
    
}