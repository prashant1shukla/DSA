#include<bits/stdc++.h>
using namespace std;
int static t[9][21];
int rodCutting(int len_arr[],int price[],int n,int L)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<L+1;j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<L+1;j++)
        {
            if(len_arr[i-1]<=j)
                t[i][j]=max(t[i][j-len_arr[i-1]]+price[i-1],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][L];
}
int main()
{
    int n=8;
    int L=20;
    int len_arr[n]={1,2,3,4,5,6,7,8};
    int price[n]={1,5,8,9,10,17,7,20};
    //cout<<"Nahi ho rha";
    cout<<rodCutting(len_arr,price,n,L);
    
}