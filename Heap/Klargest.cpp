#include<bits/stdc++.h>
using namespace std;
void Klargest(int arr[],int k)
{
    priority_queue<int, vector<int>,greater<int>>minh;
    for(int i=0;i<6;i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
            minh.pop();     
    }
    while(minh.size()>0)
    {
        cout<<minh.top()<<" ";
        minh.pop();
    }
}
int main()
{
    int arr[6]={7,10,4,3,20,15};
    int k=3;
    Klargest(arr,k);

}