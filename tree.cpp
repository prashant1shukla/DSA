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
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<(root->key)<<" ";
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
void printlevel(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
void printlevelorderline_addingNULL(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
void printlevelorderline_loop(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        cout<<endl;
    }
}
int getsize(Node *root)
{
    if(root==NULL)
        return 0;
    else   
        return(1+getsize(root->left)+getsize(root->right));
}
int getMax(Node *root)
{
    if(root==NULL)
        return INT_MIN;
    else
        return(max(root->key,max(getMax(root->left),getMax(root->right))));
    
}
int maxlevel=0;
void printLeft(Node *root,int level)
{
    if(root==NULL)
        return;
    if(maxlevel<level)
    {
        cout<<(root->key)<<" ";
        maxlevel=level;
    }
    printLeft(root->left,level+1);
    printLeft(root->right,level+1);
}
void printLeftView(Node *root)
{
    printLeft(root,1);
}
// void printLeftITR(Node *root)
// {
//     if(root==NULL)
//         return;
//     queue<Node *>q;
//     q.push(root);
//     while(q.empty()==false)
//     {
//         int count=q.size();
//         for(int i=0;i<q.size)
//     }    
    
// }
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    cout<<height(root)<<endl;

    printKdist(root,2);
    cout<<endl;

    printlevel(root);
    cout<<endl;

    printlevelorderline_addingNULL(root);
    cout<<endl;
    printlevelorderline_loop(root);

    cout<<getsize(root)<<endl;

    cout<<getMax(root)<<endl;

    printLeftView(root);
    cout<<endl;

    //printLeftITR(root);


}