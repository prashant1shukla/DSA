#include<bits/stdc++.h>
using namespace std;
bool static t[6][12];
int subsetSum(int arr[],int x,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<x+1;j++)
        {
            if(i==0)
                t[i][j]=true;
            if(j==0 && i!=0)
                t[i][j]=false;     
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<x+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=(t[i][j-arr[i-1]]||t[i-1][j]);
            else    
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][x];
}
int main()
{
    int n=5;
    int arr[n]={2,3,7,8,10};
    int x=11;
    memset(t,-1,sizeof(t));
    if(subsetSum(arr,x,n))
        cout<<"True";
    else
        cout<<"False";
}
