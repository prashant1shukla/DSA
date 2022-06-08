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
void printSpiral(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    stack<int>s;
    bool reverse=false;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(reverse)
                s.push(curr->key);
            else
                cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        if(reverse)
        {
            while(s.empty()==false)
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
    }
}
int dia=0;
int heightfordiamter(Node *root)
{
    if(root==NULL)
        return 0;
    int lh=heightfordiamter(root->left);
    int rh=heightfordiamter(root->right);
    dia=max(dia,(1+lh+rh));
    return 1+max(lh,rh);
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);

    printSpiral(root);

    cout<<heightfordiamter(root)<<endl;   
    cout<<dia<<endl;

    
}