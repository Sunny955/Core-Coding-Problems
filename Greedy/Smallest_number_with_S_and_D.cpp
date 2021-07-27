/*
The task is to find the smallest number with given sum of digits as S and number of digits as D.

 

Example 1:

Input:
S = 9 
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.
 

Example 2:

Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function smallestNumber() which takes the two integers S and D and returns a string which is the smallest number if possible, else return "-1".

 

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ S ≤ 100
1 ≤ D ≤ 6
*/
#include<bits/stdc++.h>
using namespace std;

string smallestNumber(int S, int D)
{
        string num="";
        while(S && D)
        {
            if(S>9)
            {
                num+=to_string(9);
                S-=9;
                D--;
            }
            else if(S>0)
            {
                if(D>1)
                {
                    num+=to_string(S-1);
                    S=1;
                    D--;
                }
                if(D==1)
                {
                    num+=to_string(S);
                    S=0;
                    D=0;
                }
                
            }
        }
        if(S>0)
        {
            return "-1";
        }
        reverse(num.begin(),num.end());
        return num;
}

int main()
{
    int S,D;
    cin>>S>>D;
    cout<<smallestNumber(S,D)<<endl;
}