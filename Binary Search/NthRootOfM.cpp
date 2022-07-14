#include<bits/stdc++.h>
using namespace std;
//You are given two positive integers N and M. You have to find the Nth root of M i.e. M^(1/N).
double multiply(double number,int n)
{
    double ans=1.0;
    for(int i=0;i<n;i++)
    {
        ans=ans*number;
    }
    return ans;
}
double NthRootOfM(int m,int n)
{
    double l=1;
    double r=m;
    double eps=1e-6;
    while((r-l)>eps)
    {
        double mid=l+(r-l)/2;
        if(multiply(mid,n)<m)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}      
int main()
{
    //char arr[9]={'a','b','c','d','e','f','g','h','i'};
    cout<<NthRootOfM(69,4)<<endl;
}

