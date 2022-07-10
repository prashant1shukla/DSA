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
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
bool searchRec(Node *root,int x)   // TC: O(h) and AS=O(h)->number of recursive calls
{
    if(root==NULL)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key>x)
        searchRec(root->left,x);
    else
        searchRec(root->right,x);
}
bool searchItr(Node *root,int x)       //TC: O(h) and AS=O(1)
{
    while(root!=NULL)
    {
        if(root->key==x)
            return true;
        else if(root->key>x)
            root=root->left;
        else
            root=root->right;
    }
    return false;
}
Node *insert(Node *root,int x)
{
    if(root==NULL)
        return new Node(x);
    else if(root->key>x)
        root->left=insert(root->left,x);
    else if(root->key<x)
        root->right=insert(root->right,x);
    return root;
}
Node *insertItr(Node *root,int x)
{
    Node *temp=new Node(x);
    Node *parent=NULL, *curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }
    if(root==NULL)
        return temp;
    else if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
    return root;

}
Node *getSuccessor(Node *root)
{
    Node *curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}
Node *delNode(Node *root,int x)
{
    if(root==NULL)
        return root;
    else if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else
    {
        if(root->right==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
}
Node *floor(Node *root, int x)
{
    Node *res=NULL;
    while(root!=NULL)
    {
        if(root->key==x)
            return root;
        else if(root->key>x)
            root=root->left;
        else
        {
            res=root;
            root=root->right;
        }
    }
    return res;
}
Node *ceil(Node *root, int x)
{
    Node *res=NULL;
    while(root!=NULL)
    {
        if(root->key==x)
            return root;
        else if(root->key<x)
            root=root->right;
        else
        {
            res=root;
            root=root->left;
        }
    }
    return res;
}
int main()
{
    Node *root=new Node(15);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->right=new Node(20);
    root->right->left=new Node(18);
    root->right->right=new Node(80);
    root->right->left->left=new Node(16);

    if(searchRec(root,3))
        cout<<"Yes! :)"<<endl;
    else
        cout<<"No :("<<endl;
    if(searchItr(root,9))
        cout<<"Yes! :)"<<endl;
    else
        cout<<"No :("<<endl;

    Node *root1=insert(root,7);

    preorder(root1);
    cout<<endl;

    Node *root2=insertItr(root,7);

    preorder(root2);
    cout<<endl;

    Node *root3=delNode(root,18);
    preorder(root3);
    cout<<endl;

Node *root4=floor(root,19);
Node *root5=ceil(root,19);
cout<<root4->key<<endl;
cout<<root5->key<<endl;
}