#include<bits/stdc++.h>
using namespace std;

string genrate(int n,char start)
{
    char prev=start;
    string ans="";
    for(int i=0;i<n;i++)
    {
        ans+=prev;
        if(prev=='0')
        {
            prev='1';
        }
        else
        {
            prev='0';
        }
    }
    return ans;
}

int minFlips (string S)
{
   int n=S.size();
   
   string str1=genrate(n,'0');
   string str2=genrate(n,'1');
   int dis1=0,dis2=0;
   for(int i=0;i<n;i++)
   {
       if(S[i]!=str1[i])
       {
           dis1++;
       }
       
       if(S[i]!=str2[i])
       {
           dis2++;
       }
   }
   return min(dis1,dis2);
   
}

int main()
{
    string S;
    cin>>S;
    cout<<minFlips(S)<<endl;
}