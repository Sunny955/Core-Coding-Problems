/*
Given an array, we need to find the maximum sum of absolute difference of any permutation of the given array.
Examples: 
 

Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are 
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is 
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18
*/
#include<bits/stdc++.h>
using namespace std;

int MaxAbs(vector<int>& num)
{
    sort(num.begin(),num.end());
    int n=num.size();
    vector<int> max;

    for(int i=0;i<n/2;i++)
    {
        max.push_back(num[i]);
        max.push_back(num[n-i-1]);
    }
    
    if(n%2!=0)
    {
        max.push_back(num[n/2]);
    }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans+=abs(max[i]-max[i+1]);
    }
    ans+=abs(max[0]-max[n-1]);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> num(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<MaxAbs(num)<<endl;
}