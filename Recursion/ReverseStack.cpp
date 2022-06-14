#include<bits/stdc++.h>
using namespace std;

// great question!

void insert(stack<int>&s,int ele)    //&s is important.
{
    if(s.size()==0)
    {
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,ele);
    s.push(temp);
    return;
}
void reverseStack(stack<int>&s)    //&s is important.
{
    if(s.size()==1)
        return;
    int temp=s.top();
    s.pop();
    reverseStack(s);
    insert(s,temp);
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
    while(s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    s.push(7);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(6);
    cout<<endl;
    reverseStack(s);
    vector<int>v;
    while(s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
//     for(auto it=v.rbegin();it!=v.rend();it++)
//         cout<<*it<<" ";
}

