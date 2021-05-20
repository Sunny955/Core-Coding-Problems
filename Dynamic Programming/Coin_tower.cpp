/* 
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
*/

#include<bits/stdc++.h>
using namespace std;

string findWinner(int n, int x, int y)
{
	// Write your code here .
    string out;
    int *dp=new int[n+1]();
    
    dp[0]=100;
    dp[1]=1;
    dp[x]=1;
    dp[y]=1;
    
    for(int i=2;i<=n;i++)
    {
        int ans1=-1,ans2=-1,ans3=-1,ans;
        if(dp[i]==0)
        {
            if(i-1>0)
            {
                ans1=dp[i-1]^1;
            }
            if(i-x>0)
            {
                ans2=dp[i-x]^1;
            }
            if(i-y>0)
            {
                ans3=dp[i-y]^1;
            }
        }
        
    	ans=max(ans1,max(ans2,ans3));
        dp[i]=ans;
        
    }
    
    if(dp[n]!=0)
    {
        out="Beerus";
    }
    else
    {
       out="Whis";    
    }
    return out;
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}