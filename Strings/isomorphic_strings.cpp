/*
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different
charactersin aab and xxy, i.e a and b
with frequency 2and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output:
Explanation: There are two different
charactersin aab but there are three
different charactersin xyz. So there
won't be one to one mapping between
str1 and str2.
Your Task:
You don't need to read input or print anything.Your task is to complete the function areIsomorphic() which takes the string str1 and string str2 as input parameter and  check if two strings are isomorphic. The function returns true if strings are isomorphic else it returns false.

Expected Time Complexity: O(|str1|+|str2|).
Expected Auxiliary Space: O(Number of different characters).
Note: |s| represents the length of string s.
*/
#include<bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
    {
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        int count1=0,count2=0;
        if(str1.size()!=str2.size())
        {
            return false;
        }
        
        for(int i=0;i<str1.size();i++)
        {
            if(map1.find(str1[i])==map1.end())
            {
                map1[str1[i]]=str2[i];
            }
            else
            {
                if(map1[str1[i]]==str2[i])
                {
                    map1[str1[i]]=str2[i];
                }
                else
                {
                    count1=1;
                }
            }
        }
        for(int i=0;i<str2.size();i++)
        {
            if(map2.find(str2[i])==map2.end())
            {
                map2[str2[i]]=str1[i];
            }
            else
            {
                if(map2[str2[i]]==str1[i])
                {
                    map2[str2[i]]=str1[i];
                }
                else
                {
                    count2=1;
                }
            }
        }
        if(count1==1 || count2==1)
        {
            return false;
        }
        return true;
    }

int main()
{
    string s,p;
    cin>>s>>p;
    cout<<areIsomorphic(s,p)<<endl;
}