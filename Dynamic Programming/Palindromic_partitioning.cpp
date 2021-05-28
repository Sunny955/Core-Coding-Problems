/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)
*/

#include<bits/stdc++.h>
using namespace std;

int dp[500][500];
int isPallindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int PP(string str,int i,int j){
    if(dp[i][j]!=-1)
        return t[i][j];
    if(i>=j || isPallindrome(str,i,j)){
        t[i][j]=0;
        return 0;
    }
    int ans = INT_MAX,temp;
    for(int k=i;k<j;k++){
        if(isPallindrome(str,i,k)){
            temp = 1+PP(str,k+1,j);
            ans = min(ans,temp);
        }
    }
    return dp[i][j] = ans;
}
int palindromicPartition(string str){
    memset(t,-1,sizeof(t));
    return PP(str,0,str.length()-1);
}
