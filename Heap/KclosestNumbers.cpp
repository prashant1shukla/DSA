#include<bits/stdc++.h>
using namespace std;
void KclosestNumbers(int arr[],int k, int x)
{
    priority_queue<pair<int,int>>maxh;
    int diff[6];
    for(int i=0;i<6;i++)
    {
        diff[i]=arr[i]-x;
    }
    for(int i=0;i<6;i++)
    {
        maxh.push({diff[i],arr[i]});
        if(maxh.size()>k)
            maxh.pop(); 
    }
    while(maxh.size()!=0)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
    
}
int main()
{
    int arr[6]={7,10,4,3,20,15};
    int k=3;
    int x=5;
    KclosestNumbers(arr,k,x);
}