/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output: 
no on
is
Explanation:
There are 2 groups of
anagrams "no", "on" make group 1.
"is" makes group 2. 

Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.


Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.


Constraints:
1<=N<=100
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& strs)
{
    vector<vector<string>> ans;
    int n=strs.size();
    if(n==0)
    {
        return ans;
    }
    unordered_map<string,vector<string>> map;
    
    for(auto i:strs)
    {
        string s=i;
        sort(s.begin(),s.end());
        map[s].push_back(i);
    }
    
    for(auto i:map)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string> strs(n,"");
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
    vector<vector<string>> ans=Anagrams(strs);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<endl;
        }
    }
}