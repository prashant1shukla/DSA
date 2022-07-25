#include<bits/stdc++.h>
using namespace std;
int knapsackRecursive(int wt[],int val[],int W,int n)
{
    if(n==0||W==0)
        return 0;
    if(wt[n-1]<=W)
        return max(val[n-1]+knapsackRecursive(wt,val,W-wt[n-1],n-1),knapsackRecursive(wt,val,W,n-1));
    else if(wt[n-1]>W)
        return knapsackRecursive(wt,val,W,n-1);
}
int main()
{
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int W=7;
    cout<<knapsackRecursive(wt,val,W,n);
}