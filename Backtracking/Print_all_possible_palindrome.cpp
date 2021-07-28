/*

This question is similar to MCM

Given a string, print all possible palindromic partitions
Difficulty Level : Hard
Last Updated : 08 Jun, 2021
Given a string, find all possible palindromic partitions of given string.
Example: nitin
         n i t i n 
         n iti n
         nitin
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int l,int h)
{
    while(h>l)
    {
         if(s[l]!=s[h])
         {
            return false;
         }
        
        l++;
        h--;
        
    }
    return true;
}

void findAll(string s,vector<string>& current,vector<vector<string>>& ans,int start,int end)
{
    if(end<start)
    {
        ans.push_back(current);
        return;
    }
    
    for(int i=start;i<=end;i++)
    {
        if(isPalindrome(s,start,i))
        {
            current.push_back(s.substr(start,i-start+1));
            findAll(s,current,ans,i+1,end);
            current.pop_back();
        }
    }
}

void allPalPartition(string s)
{
    int n=s.size();
    vector<string> current;
    vector<vector<string>> ans;
    
    findAll(s,current,ans,0,n-1);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string s;
    cin>>s;
    allPalPartition(s);
}