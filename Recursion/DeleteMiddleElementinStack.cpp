#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int>&s,int k)    //&s is important.   middle means only=n/2+1
{
    if(k==1)
    {
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    deleteMiddle(s,k-1);
    s.push(temp);
    return;
}
int main()
{
    stack<int>s;
    s.push(7);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(6);
    int k=3;
    deleteMiddle(s,k);
    vector<int>v;
    while(s.size()!=0)
    {
        v.push_back(s.top());
        s.pop();
    }
    for(auto it=v.rbegin();it!=v.rend();it++)
        cout<<*it<<" ";
}

