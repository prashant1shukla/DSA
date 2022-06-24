#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {   
        key=k;
        left=right=NULL;
    }
};
bool Search(Node *root,int x)
{
    if(root==NULL)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key>x)
        return Search(root->left, x);
    else 
        return Search(root->right,x);
}

int main()
{
    Node *root=new Node(20);
    root->left=new Node(10);
    root->right=new Node(30);
    root->left->left=new Node(5);
    root->left->right=new Node(15);
    if(Search(root,5))
        cout<<"y"<<endl;
    else    
        cout<<"N"<<endl;

    
}