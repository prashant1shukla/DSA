#include<bits/stdc++.h>
using namespace std;
int static t[5][8];
int knapsackTopDown(int wt[],int val[],int W,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 ||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)   
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];

}
int main()
{
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int W=7;
    memset(t,-1,sizeof(t));
    cout<<knapsackTopDown(wt,val,W,n);
}