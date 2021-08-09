/*
Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
 

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22
 

Example 2:

Input: s = aabcbcbcabcc, k = 3
Output: 27
Explaination: We remove two 'c' and one 'b'. 
Now we get the value as 32 + 32 + 32.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

 

Expected Time Complexity: O(N*logN)  where N is the length of string
Expected Auxiliary Space: O(N)

 

Constraints:
1 ≤ k ≤ |string length| ≤ 100
*/
#include<bits/stdc++.h>
using namespace std;

int minValue(string s, int k)
{
        priority_queue <int> pq;
        
        unordered_map<int,int> map;
        for(int i=0;i<s.size();i++)
        {
            if(map.find(s[i]-'a')==map.end())
            {
                map[s[i]-'a']=1;
            }
            else
            {
                map[s[i]-'a']++;
            }
        }
        
        for(auto i:map)
        {
            pq.push(i.second);
        }
        
        while(k>0)
        {
            int a=pq.top();
            pq.pop();
            a--;
            pq.push(a);
            k--;
        }
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top()*pq.top();
            pq.pop();
        }
        return ans;
        
}

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<minValue(s,k)<<endl;
}