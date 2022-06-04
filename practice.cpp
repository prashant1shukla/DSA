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
        left=NULL;
        right=NULL;
    }
};
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}
int height(Node *root)
{
    if(root==NULL)
        return 0;
    return (1+max(height(root->left),height(root->right)));
}
void kdist(Node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
        cout<<root->key<<" ";
    else 
        kdist(root->left,k-1);
        kdist(root->right,k-1);
}
void bfs(Node *root)
{
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
void levelorderline(Node *root)
{
    queue<Node *>q;
    q.push(root);
    while(q.size()!=NULL)
    {
        int cnt=q.size();
    for(int i=0;i<cnt;i++)
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
int size(Node *root)
{
    if(root==NULL)
        return 0;
    else 
        return (1+size(root->left)+size(root->right));   
}
int maxNode(Node *root)
{
    if(root==NULL)
        return INT_MIN;
    return max(root->key,max(maxNode(root->left),maxNode(root->right)));
}
void leftView(Node *root)
{
    if(root==NULL)  
        return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        int cnt=q.size();
        for(int i=0;i<cnt;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<curr->key<<" "; //not using else break; as hume aur ander jana h.
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}
//Children Sum prop-> if the sum of the children is equal to the key at node. for all nodes.
bool childrenSum(Node *root)
{
    if(root==NULL)
        return true;
    if(root->left==NULL&&root->right==NULL)
        return true;
    int sum=0;
    if(root->left!=NULL)
        sum+=root->left->key;
    if(root->right!=NULL)
        sum+=root->right->key;
    return(root->key==sum && childrenSum(root->left) && childrenSum(root->right));

}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<height(root)<<endl;
    kdist(root,2);
    cout<<endl;
    bfs(root);
    cout<<endl;
    levelorderline(root);
    cout<<size(root)<<endl;
    cout<<maxNode(root)<<endl;
    if(childrenSum(root))
        cout<<"haa hai bhai"<<endl;
    else
        cout<<"Nahi hai bhai"<<endl;
}