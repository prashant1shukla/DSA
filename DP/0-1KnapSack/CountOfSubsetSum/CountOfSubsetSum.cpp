#include<bits/stdc++.h>
using namespace std;
int t[6][11];
int CntSubsetSum(int arr[],int sum, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum;j++)
        {
            if(j==0)
                t[i][j]=1;
            else if(i==0 && j!=0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=(t[i][j-arr[i-1]]+t[i-1][j]);
            else 
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int n=5;
    int arr[n]={2,3,5,8,10};
    int sum=10;
    memset(t,-1,sizeof(t));
    cout<<(CntSubsetSum(arr,sum,n));
}
