#include<bits/stdc++.h>
using namespace std;
int ConnectRopes(int arr[])
{
    priority_queue<int,vector<int>,greater<int>>minh;
    int cost=0;
    for(int i=0;i<5;i++)
        minh.push(arr[i]);
    while(minh.size()>=2)
    {
        int first=minh.top();
        minh.pop();
        int second=minh.top();
        minh.pop();
        cost+=first+second;
        minh.push(first+second);
    }
    return cost;
    
}
int main()
{
    int arr[5]={1,2,3,4,5};
    //int k=3;
    cout<<ConnectRopes(arr);
}