/*
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

Examples: 

Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80

Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30, buy at 8 and sell at 80

Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
Output:  72
Buy at price 8 and sell at 80.

Input:   price[] = {90, 80, 70, 60, 50}
Output:  0
Not possible to earn.
*/

#include<bits/stdc++.h>
using namespace std;

int Max_Profit(int *price,int n)
{
    vector<int> profit(n,0);
    
    int max_price=price[n-1];
    for(int i=n-2;i>=0;i--)
    {
       if(price[i]>max_price)
       {
           max_price=price[i];
       }
       profit[i]=max(profit[i+1],max_price-price[i]);
    }
    int min_price=price[0];
    for(int i=1;i<n;i++)
    {
        if(min_price>price[i])
        {
            min_price=price[i];
        }
        profit[i]=max(profit[i-1],profit[i]+(price[i]-min_price));
    }
    return profit[n-1];
}

int main()
{
    int n;
    cin>>n;
    
    int price[n];
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    cout<<Max_Profit(price,n)<<endl;
}