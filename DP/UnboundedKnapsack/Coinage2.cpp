#include<bits/stdc++.h>
using namespace std;
int static t[4][6];
int Coinage2(int coins[],int sum,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=0;
            if(i==0)
                t[i][j]=INT_MAX-1;
            if(i==1)
            {
                if(j%coins[i-1]==0)
                    t[i][j]=j/coins[i-1];
                else
                    t[i][j]=INT_MAX-1;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coins[i-1]<=sum)
                t[i][j]=min(t[i][j-coins[i-1]]+1,t[i-1][j]+0);    // t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);

            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int n=3;
    int sum=5;
    memset(t,-1,sizeof(t));
    int coins[n]={1,2,3};
    cout<<Coinage2(coins,sum,n);
}