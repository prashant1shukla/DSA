#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
struct myStack
{
    Node *head;
    int sz;
    myStack()
    {
        sz=0;
        head=NULL;
    }
    void push(int x)
    {
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    void pop()
    {
        if(head==NULL)
            cout<<"Stack is empty";
        int res=head->data;
        Node *temp=head;
        head=head;
    }
};
int main()
{
    myStack s();


    

}