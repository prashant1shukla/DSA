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
    if(root==NULL)
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
void printLeftView2(Node *root,vector<int>ans,int level)
{
    if(root==NULL)
        return;
    if(level==ans.size())
    {
        ans.push_back(root->key);
    }
    printLeftView2(root->left,ans,level+1);
    printLeftView2(root->right,ans,level+1);


    for(auto x:ans)
        cout<<x<<" ";
}
void printLeftITR(Node *root)  //left view means printing the first elemtns of each level. easy when we will go with levelorder/bfs
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
            if(i==0)
                cout<<(curr->key)<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}
bool isChildrenSum(Node *root)
{
    if(root==NULL)
        return true;
    if((root->left==NULL)&&(root->right==NULL))
        return true;
    int sum=0;
    if(root->left!=NULL)
        sum+=root->left->key;
    if(root->right!=NULL)
        sum+=root->right->key;
    return(root->key==sum && isChildrenSum(root->left) && isChildrenSum(root->right));
}
bool isBalanced(Node *root)//where we already have the height function.
{
    if(root==NULL)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}
int isBalanced2(Node *root)
{
    if(root==NULL)
        return 0;
    int lh=isBalanced2(root->left);
    if(lh==-1)
        return -1;
    int rh=isBalanced2(root->right);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    else
        return (max(lh,rh)+1);
}
int maxWidth(Node *root)
{
    if(root==NULL)
        return 0;
    queue<Node *>q;
    q.push(root);
    int res=0;
    while(q.empty()==false)
    {
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}
Node *BTtoDLL(Node *root)
{
    if(root==NULL)
        return root;
    static Node* prev=NULL;
    Node *head=BTtoDLL(root->left);
    if(prev==NULL)
        head=root;
    else 
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTtoDLL(root->right);
    return head;   
}
void printlist(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->key<<" ";
        curr=curr->right;
    }
    cout<<endl;
}
//CONSTRUCT BINARY TREE FROM INORDER, PREORDER- PENDING.

// void printSpiral(Node *root)
// {
//     if(root==NULL)
//         return;
//     queue<Node *>q;
//     stack<int>s;
//     bool reverse=false;
//     q.push(root);
//     while(q.empty()==false)
//     {
//         int count=q.size();
//         for(int i=0;i<count;i++)
//         {
//             Node *curr=q.front();
//             q.pop();
//             if(reverse)
//                 s.push(curr->key);
//             else
//                 cout<<curr->key<<" ";
//             if(curr->left!=NULL)
//                 q.push(curr->left);
//             if(curr->right!=NULL)
//                 q.push(curr->right);
//         }
//         if(reverse)
//         {
//             while(s.empty()==false)
//             {
//                 cout<<s.top()<<" ";
//                 s.pop();
//             }
//         }
//         reverse=!reverse;
//         cout<<endl;
//     }
// }
// int dia=0;
// int heightfordiamter(Node *root)
// {
//     if(root==NULL)
//         return 0;
//     int lh=heightfordiamter(root->left);
//     int rh=heightfordiamter(root->right);
//     dia=max(dia,(1+lh+rh));
//     return 1+max(lh,rh);
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

    printLeftITR(root);
    cout<<endl;

    cout<<isChildrenSum(root)<<endl;

    cout<<isBalanced(root)<<endl;
    cout<<isBalanced2(root)<<endl;

    cout<<maxWidth(root)<<endl;
    
    Node *head=BTtoDLL(root);
	printlist(head);
    cout<<endl;

    //printSpiral(root);  runtime-error due to running all code together.

    // cout<<heightfordiamter(root)<<endl;     runtime-error due to running all code together.
    // cout<<dia<<endl;
    

}