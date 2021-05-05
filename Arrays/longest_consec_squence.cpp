/*  
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

*/

#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
       
       set<int> s;
       for(int i=0;i<N;i++)
       {
          
           s.insert(arr[i]);
       }
       set<int>::iterator itr;
       itr=s.begin();
       int start=*(itr);
       int count=1;
       int max_count=INT_MIN;
       while(itr!=s.end())
       {
           itr++;
           if(start+1==*(itr))
           {
               count++;
           }
           else
           {
               if(count>max_count)
               {
                   max_count=count;
               }
               count=1;
           }
           start=*(itr);
       }
       return max_count;
}

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int ans=findLongestConseqSubseq(arr,N);
    cout<<ans<<endl;
}

