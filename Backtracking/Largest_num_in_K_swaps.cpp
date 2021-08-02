/*
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3 
with 5, 4 with 5 and finally 3 with 4 

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.


Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10
*/
#include<bits/stdc++.h>
using namespace std;

string max;
    
    
string swap(string str,int i,int j)
{
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    return str;
}
    
void findMax(string str,int k)
{
    if(stoi(str)>stoi(max))
    {
        max=str;
    }
       
    if(k==0)
    {
        return;
    }
       
       for(int i=0;i<str.size()-1;i++)
       {
           for(int j=i+1;j<str.size();j++)
           {
               if((str[j]-'0')>(str[i]-'0'))
               {
                   string swapped=swap(str,i,j);
                   findMax(swapped,k-1);
                  
               }
               
           }
       }
}
    
    string findMaximumNum(string str, int k)
    {
    
       if(k==0)
       {
           return "";
       }
        
       max=str;
       findMax(str,k);
       return max;
    }