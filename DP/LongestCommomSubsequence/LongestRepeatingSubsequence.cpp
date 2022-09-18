#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];

int LRS(string x,int n)
{
    string y=x;
    int m=n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1]&&i!=j)
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][m];
    
}
int main()
{
    string x="aabcdgh";
    int n=7;
    memset(t,-1,sizeof(t));
    cout<<LRS(x,n);
    
}
