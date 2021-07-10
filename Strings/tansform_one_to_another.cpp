/*
Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

Examples: 

Input:  A = "ABD", B = "BAD"
Output: 1
Explanation: Pick B and insert it at front.

Input:  A = "EACBD", B = "EABCD"
Output: 3
Explanation: Pick B and insert at front, EACBD => BEACD
             Pick A and insert at front, BEACD => ABECD
             Pick E and insert at front, ABECD => EABCD
*/
#include <bits/stdc++.h>
using namespace std;

int Transform(string A,string B)
{
    set<char> s1;
    set<char> s2;
    if(A.size()!=B.size())
    {
        return -1;
    }
    for(int i=0;i<A.size();i++)
    {
        s1.insert(A[i]);
        s2.insert(B[i]);
    }
    
    if(s1!=s2)
    {
        return -1;
    }
    int i=A.size()-1,j=A.size()-1;
    int ans=0;
    while(i>=0 && j>=0)
    {
        if(A[i]!=B[j])
        {
            while(i>=0 && A[i]!=B[j])
            {
                i--;
                ans++;
            }
        }
        else
        {
            if(i>=0)
            {
                i--;
                j--;
            }
        }
    }
    return ans;
    
}
int main() 
{
	string A,B;
	cin>>A>>B;
	cout<<Transform(A,B)<<endl;
	return 0;
}