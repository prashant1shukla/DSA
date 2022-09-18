#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int LCS(string x,string y,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=0;
        }
    }
    // return t[n][m];
    int ans=-1;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(t[i][j]>ans)
                ans=t[i][j];
        }
    }
    return ans;
}
int main()
{
    string x="abcdgh";
    string y="abedfhg";
    int n=6,m=7;
    memset(t,-1,sizeof(t));
    cout<<LCS(x,y,n,m);
}
