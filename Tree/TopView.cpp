#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        data =k;
        left=NULL;
        right=NULL;
    }
};
vector<int>v;
  
void top(Node *root,int hd,int lvl,map<int,vector<int,int>>&mp)
{
    if(root==NULL)
        return;
    if(mp.find(hd)==mp.end())
        mp[hd]=make_pair(root->data,lvl);
    else
    {
        pair < int, int > p = mp[hd];
        if (p.second > lvl)
        {
            mp[hd].second = lvl;
            mp[hd].first = root -> data;
        }
    }
    //if(root->left==NULL)
    top(root->left,hd-1,lvl+1,mp);
    //mp[hd]=(root->data);
    //if(root->right!=NULL)
    top(root->right,hd+1,lvl+1,mp);
    // for(auto x:mp)
    //         cout<<(x.second);
}
vector <int> topView(Node *root) {
    v.clear();
    map<int,pair<int,int>>mp;
    mp.clear();
    top(root,0,0,mp);
    for(auto x:mp)
        v.push_back(x.second.first);
    return v;
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);

    //printSpiral(root);

    topView(root);
    for(auto x:v)
     cout<<x<<" ";  
    

    
}