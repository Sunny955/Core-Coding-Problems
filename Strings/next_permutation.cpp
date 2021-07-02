#include <bits/stdc++.h>
using namespace std;

void Swap(vector<int>& arr,int i,int j)
{
    swap(arr[i],arr[j]);
}
vector<int> nextPermutation(int N, vector<int> arr)
{
      
      if(N<=1)
      {
          return arr;
      }
       
      int i=arr.size()-2;
      while(i>=0 && arr[i]>=arr[i+1])
      {
          i--;
      }
       
      if(i>=0)
      {
          int j=arr.size()-1;
          while(arr[i]>=arr[j])
          {
              j--;
          }
          Swap(arr,i,j);
      }
       reverse(arr.begin()+i+1,arr.end());
       return arr;
}

int main() 
{
    int N;
    cin>>N;
    
    vector<int> arr(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans=nextPermutation(N,arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}