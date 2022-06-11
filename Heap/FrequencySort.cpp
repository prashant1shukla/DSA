#include<bits/stdc++.h>
using namespace std;
void FrequencySort(int arr[])
{
    priority_queue<pair<int,int>>maxh;
    unordered_map<int,int>mp;
    for(int i=0;i<12;i++)
        mp[arr[i]]++;

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        maxh.push({it->second,it->first});
    }
    while(maxh.size()!=0)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
    
}
int main()
{
    int arr[12]={7,7,7,10,10,4,3,20,15,4,4,4};
    //int k=3;
    FrequencySort(arr);
}