/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secFrequent() which takes the string array arr[] and its size N as inputs and returns the second most frequent string in the array.


Expected Time Complexity: O(N*max(|Si|).
Expected Auxiliary Space: O(N*max(|Si|).


Constraints:
1<=N<=103
*/
#include<bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> map;
        set<string> st;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
            if(map.find(arr[i])==map.end())
            {
                map[arr[i]]=1;
            }
            else
            {
                map[arr[i]]++;
                if(map[arr[i]]>maxi)
                {
                    maxi=map[arr[i]];
                }
            }
            
        }
        string ans;
        int sec_max=INT_MIN;
        for(auto i:st)
        {
            if(map[i]!=maxi)
            {
                if(map[i]>sec_max)
                {
                    sec_max=map[i];
                    ans=i;
                }
            }
        }
        
        return ans;
    }
int main()
{
    int n;
    cin>>n;
    string arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<secFrequent(arr,n)<<endl;
}