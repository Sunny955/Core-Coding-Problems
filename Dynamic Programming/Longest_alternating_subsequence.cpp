/*
A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :
x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....
Your task is to find the longest such sequence.

Example 1:

Input: nums = {1,5,4}
Output: 3
Explanation: The entire sequenece is a 
alternating sequence.
Examplae 2:

Input: nums = {1,17,5,10,13,15,10,5,16,8}
Ooutput: 7
Explanation: There are several subsequences
that achieve this length. 
One is {1,17,10,13,10,16,8}.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function AlternatingaMaxLength() which takes the sequence  nums as input parameter and returns the maximum length of alternating sequence.

*/

#include<bits/stdc++.h>
using namespace std;

int AlternatingaMaxLength(vector<int>&nums)
		{
		    int inc=1,dec=1;
		    
		    for(int i=1;i<nums.size();i++)
		    {
		        if(nums[i-1]<nums[i])
		        {
		            inc=dec+1;
		        }
		        else if(nums[i-1]>nums[i])
		        {
		            dec=inc+1;
		        }
		    }
		    
		    return max(inc,dec);
		    
		}

int main()
{
   int n,a;
   cin>>n;
   
   vector<int> input(n,0);
   for(int i=0;i<n;i++)
   {
       cin>>a;
       input.push_back(a);
   }
   cout<<AlternatingaMaxLength(input)<<endl;
}