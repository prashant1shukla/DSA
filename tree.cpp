#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key =k;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<(root->key)<<" ";
        inorder(root->right);
    }
}
int height(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return (max(height(root->left),height(root->right))+1);
}
void printKdist(Node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
        cout<<(root->key)<<" ";
    else
        printKdist(root->left,k-1);
        printKdist(root->right,k-1);
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    inorder(root);
    cout<<endl;
    cout<<height(root)<<endl;
    printKdist(root,2);
}