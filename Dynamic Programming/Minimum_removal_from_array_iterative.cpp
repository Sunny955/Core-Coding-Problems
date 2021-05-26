int MinRemoval_Itr(int *arr,int n,int k,int **dp)
{
    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
    }
    
    for(int i=1;i<n;i++)
    {
        dp[n-1][i]=0;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[j]-arr[i]>k)
            {
                dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    int N,K;
    cin>>N;
    
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cin>>K;
    int **dp=new int*[N];
    for(int i=0;i<N;i++)
    {
        dp[i]=new int[N];
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<MinRemoval_Itr(arr,N,K,dp)<<endl;
}
