#include<bits/stdc++.h>
using namespace std;
struct myStack
{
    int *arr;
    int cap;
    int top1;
    myStack(int c)
    {
        cap=c;
        arr= new int[cap];
        top1=-1;
    }
    void push(int x)
    {
        if(top1==cap-1)
            cout<<"Full stack";
        top1++;
        arr[top1]=x;
    }
    void pop()
    {
        if(top1==-1)
            cout<<"Empty Stack";
        top1--;
    }
    int top()
    {
        if(top1==-1)
            return -1;
        return arr[top1];
    }
    int size()
    {
        return top1+1;
    }
    bool isEmpty()
    {
        if(top1==-1) 
            return true;
        else
            return false;
    }
    
};
int main()
{
    myStack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;


    

}