/*
Given an array and a number, print all subsets with sum equal to given the sum.
Examples: 
 

Input :  arr[] =  {2, 5, 8, 4, 6, 11}, sum = 13
Output : 
5 8
2 11
2 5 6

Input : arr[] =  {1, 5, 8, 4, 6, 11}, sum = 9
Output :
5 4
1 8
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& temp)
{
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void GetSubset(int *arr,int n,int sum,vector<int>& temp)
{
    if(sum==0)
    {
        printVector(temp);
        return;
    }
    
    if(n==0)
    {
        return;
    }
    
    temp.push_back(arr[0]);
    GetSubset(arr+1,n-1,sum-arr[0],temp);
    
    temp.pop_back();
    GetSubset(arr+1,n-1,sum,temp);
}

void printAllSubsets(int* arr,int n,int sum)
{
    vector<int> temp;
    GetSubset(arr,n,sum,temp);
}

int main()
{
    int arr[] = { 2, 5, 8, 4, 6, 11 };
    int sum = 13;
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllSubsets(arr, n, sum);
    return 0;
}