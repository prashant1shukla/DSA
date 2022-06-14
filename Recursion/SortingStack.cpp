#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&s,int temp)    //&s is important.
{
    if(s.size()==0||s.top()<=temp)
    {
        s.push(temp);
            return;
    }
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void sort(stack<int>&s)    //&s is important.
{
    if(s.size()==1)
        return;
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
int main()
{
    stack<int>s;
    s.push(7);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(6);
    sort(s);
    vector<int>v;
    while(s.size()!=0)
    {
        v.push_back(s.top());
        s.pop();
    }
    for(auto it=v.rbegin();it!=v.rend();it++)
        cout<<*it<<" ";
}

