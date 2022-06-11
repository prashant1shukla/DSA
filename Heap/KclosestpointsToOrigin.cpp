#include<bits/stdc++.h>
using namespace std;
void KclosestpointsToOrigin(int arr[4][2],int k)
{
    priority_queue<pair<int,pair<int,int>>>maxh;
    for(auto i=0;i<4;i++)
    {
        maxh.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
        if(maxh.size()>k)
            maxh.pop();
    }
    while(maxh.size()!=0)
    {
        cout<<maxh.top().second.first<<" "<<maxh.top().second.second<<" "<<endl;
        maxh.pop();
    }
    
}
int main()
{
    int arr[4][2]={1,3,-2,2,5,8,1,0};
    int k=3;
    KclosestpointsToOrigin(arr,k);
}