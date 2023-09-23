#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
int LCS(string x,string y,int n,int m)
{
    if(n==-1 || m==-1)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(x[n]==y[m])
        return dp[n][m] = 1+LCS(x,y,n-1,m-1);
    else
        return dp[n][m] = max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
}
int main()
{
    string x="abcdgh";
    string y="abedfhg";
    int n=6,m=7;
    memset(t,-1,sizeof(t));
    cout<<LCS(x,y,n,m);
}
