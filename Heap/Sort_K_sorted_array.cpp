#include<bits/stdc++.h>
using namespace std;
void Ksorted(int arr[],int k)
{
    priority_queue<int,vector<int>,greater<int>>minh;
    vector<int>v;
    for(int i=0;i<7;i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
        {
            v.push_back(minh.top());
            minh.pop();
        }     
    }
    while(minh.size()>0)
    {
        v.push_back(minh.top());
        minh.pop();
    }
    for(auto x:v)
        cout<<x<<" ";  
}
int main()
{
    int arr[]={6,5,3,2,8,10,9};
    int k=3;
    Ksorted(arr,k);

}