#include<bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) 
{
    unordered_map<string,int> map;
    map["I"]=1;
    map["V"]=5;
    map["X"]=10;
    map["L"]=50;
    map["C"]=100;
    map["D"]=500;
    map["M"]=1000;
    map["CM"]=900;
    map["XL"]=40;
    map["CD"]=400;
    map["IX"]=9;
    map["IV"]=4;
    map["XC"]=90;
   
    
    
    if(str.size()==1)
    {
        return map[str.substr(0,1)];
    }
    int n=str.size();
    int num=0,i=0;
    while(i<n)
    {
        if(i<n-1 && map[str.substr(i,2)]>0)
        {
            num+=map[str.substr(i,2)];
            i+=2;
        }
        else
        {
            num+=map[str.substr(i,1)];
            i+=1;
        }
    }
    return num;
}

int main()
{
    string str;
    cin>>str;
    
    cout<<romanToDecimal(str)<<endl;
}