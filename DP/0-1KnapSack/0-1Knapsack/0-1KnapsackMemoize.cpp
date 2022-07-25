#include<bits/stdc++.h>
using namespace std;
int static t[5][8];
int knapsackMemoize(int wt[],int val[],int W,int n)
{
    if(n==0||W==0)
        return 0;
    if(t[n][W]!=-1)
        return t[n][W];
    if(wt[n-1]<=W)
        return t[n][W]=max(val[n-1]+knapsackMemoize(wt,val,W-wt[n-1],n-1),knapsackMemoize(wt,val,W,n-1));
    else if(wt[n-1]>W)
        return t[n][W]=knapsackMemoize(wt,val,W,n-1);
}
int main()
{
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int W=7;
    memset(t,-1,sizeof(t));
    cout<<knapsackMemoize(wt,val,W,n);
}