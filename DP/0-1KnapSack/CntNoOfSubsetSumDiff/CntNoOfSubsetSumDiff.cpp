#include<bits/stdc++.h>
using namespace std;
// s1-s2=given diff    ----(eq 1)
//we will have s1+s2=total sum   ----(eq 2)
//eq2-eq1
//s1=(diff+total sum)/2
//NOW QUESTION IS EASY JUST COUNT THE NUMBER OF SUBSET SUM.
int static t[6][35];
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
int CntNoOfSubsetSumDiff(int arr[],int diff,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int x=(diff+sum)/2;
    return CntSubsetSum(arr,x,n);
}
int main()
{
    int n=5;
    int arr[n]={2,3,5,6,8,10};
    int diff=1;
    memset(t,-1,sizeof(t));
    cout<<CntNoOfSubsetSumDiff(arr,diff,n);
}