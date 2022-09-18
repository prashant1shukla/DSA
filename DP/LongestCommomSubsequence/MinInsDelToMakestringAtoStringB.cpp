#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
void MinInsDelToMakeStringAtoStringB(string x,string y,int n,int m)
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
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    int lcs=t[n][m];
    cout<<"Min Insertion:"<<x.length()-lcs<<endl;
    cout<<"Min Del:"<<y.length()-lcs<<endl;
}
int main()
{
    string x="abcdgh";
    string y="bed";
    int n=6,m=3;
    memset(t,-1,sizeof(t));
    MinInsDelToMakeStringAtoStringB(x,y,n,m);
}
