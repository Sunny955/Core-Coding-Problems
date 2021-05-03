/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping. */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{ 
   sort(intervals.begin(),intervals.end());
   vector<vector<int>> ans;
   stack<pair<int,int>> s;
   s.push({intervals[0][0],intervals[0][1]});
   for(int i=1;i<intervals.size();i++)
   {
       int start1=s.top().first;
       int end1=s.top().second;
       int start2=intervals[i][0];
       int end2=intervals[i][1];
       
       if(start2>end1)
       {
           s.push({intervals[i][0],intervals[i][1]});
       }
       else
       {
           s.pop();
           end1=max(end1,end2);
           s.push({start1,end1});
       }
   }
   
   while(!s.empty())
   {
       ans.push_back({s.top().first,s.top().second});
       s.pop();
   }
   sort(ans.begin(),ans.end());
   return ans;
}

int main()
{
    int n,a;
    cin>>n;
    
    vector<vector<int>> input;
    for(int i=0;i<n;i++)
    {
        vector<int> p;
        for(int j=0;j<2;j++)
        {
            cin>>a;
            p.push_back(a);
        }
        input.push_back(p);
        p.clear();
    }
    
    vector<vector<int>> ans;
    ans=merge(input);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

