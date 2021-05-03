#include<bits/stdc++.h>
using namespace std;

class Pair
{
    public:int min;
            int max;
};

Pair min_max(vector<int>& arr,int n)
{
    Pair minmax;    
    int i;
     
    //If there is only one elements then
    min=arr[0] and max=arr[0]
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];    
        return minmax;
    }
     
    // If there are more than one elements,
    // then initialize min and max
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
     
    for(i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)    
            minmax.max = arr[i];
             
        else if (arr[i] < minmax.min)    
            minmax.min = arr[i];
    }
    return minmax;
}


int main()
{
    int n,a;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
       cin>>a;
       arr.push_back(a);
    }
    Pair ans = min_max(arr,n);
    cout<<ans.min<<" "<<ans.max<<endl;
}
