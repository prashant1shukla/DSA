#include<bits/stdc++.h>
using namespace std;
void TopKfrequent(int arr[],int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
    unordered_map<int,int>mp;
    for(int i=0;i<12;i++)
        mp[arr[i]]++;

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        minh.push({it->second,it->first});
        if(minh.size()>k)
            minh.pop(); 
    }
    while(minh.size()!=0)
    {
        cout<<minh.top().second<<" ";
        minh.pop();
    }
    
}
int main()
{
    int arr[12]={7,7,7,10,10,4,3,20,15,4,4,4};
    int k=3;
    TopKfrequent(arr,k);
}