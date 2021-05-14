/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
*/

#include <bits/stdc++.h>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    int *ans=new int[n]();
    ans[0]=arr[0];
    ans[1]=arr[1];
    int max_prof=arr[0];
    for(int i=2;i<n;i++)
    {
        for(int j=i-2;j>=0;j--)
        {
            ans[i]=max(ans[i],arr[i]+ans[j]);
        }
        if(ans[i]>max_prof)
        {
            max_prof=ans[i];
        }
    }
    return max_prof;
}

int main()
{
   int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}