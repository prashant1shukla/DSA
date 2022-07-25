#include<bits/stdc++.h>
using namespace std;
bool static t[6][12];
vector<int> isSubsetPoss(int arr[],int sum,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
                t[i][j]=true;
            if(i==0 && j!=0)
                t[i][j]=false;     
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=(t[i][j-arr[i-1]]||t[i-1][j]);
            else    
                t[i][j]=t[i-1][j];
        }
    }
    vector<int>v;
    for(int j=0;j<=sum;j++)
    {
        if(t[n][j]==true)
        {
            v.push_back(j);
        }
    }
    return v;
}
int minSubsetSumDiff(int arr[],int n)
{
    int range=0;
    for(int i=0;i<n;i++)
        range+=arr[i];
    vector<int>v=isSubsetPoss(arr,range,n);
    int mn=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        mn=min(mn,abs(range-2*v[i]));
    }
    return mn;    
}
int main()
{
    int n=5;
    int arr[n]={2,3,7,8,11};
    memset(t,-1,sizeof(t));
    cout<<minSubsetSumDiff(arr,n);

}
