#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAdjList(vector<int>adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void BFS(vector<int>adj[],int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(q.size()!=0)
    {
        int cnt=q.size();
        for(int i=0;i<cnt;i++)
        {
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(auto x:adj[u])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
    }
}
void BFS22(vector<int>adj[],int s,bool visited[])
{
    cout<<"BFS with source s="<<s<<endl;
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
    cout<<endl;
}
void BFS2(vector<int>adj[],int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            BFS22(adj,i,visited);
        }
    }
}
void BFS_cnt(vector<int>adj[],int s,bool visited[])
{
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int count_connectingcmp_undirected(vector<int>adj[],int v)
{
    bool visited[v];
    int cnt=0;
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            cnt++;
            BFS_cnt(adj,i,visited);
        }
    }
    return cnt;
}
// void BFS2(vector<int>adj[],int v)       MY SOLUTION
// {
//     bool visited[v];
//     queue<int>q;
//     for(int i=0;i<v;i++)
//         visited[i]=false;
//     for(int i=0;i<v;i++)
//     {
//         for(int i=0;i<v;i++)
//             visited[i]=false;
//         cout<<"Traversal with s= "<<i<<endl;
//         if(visited[i]==false)
//         {
//             q.push(i);
//             visited[i]=true;
//             while(q.size()!=0)
//             {
//                 int cnt=q.size();
//                 int u=q.front();
//                 q.pop();
//                 cout<<u<<" ";
//                     for(auto x:adj[u])
//                     {
//                        if(visited[x]==false)
//                         {
//                             visited[x]=true;
//                             q.push(x);
//                         }
//                     }             
//             }

//         }
//         cout<<endl;
//     }
// }
void DFSRec(vector<int>adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u:adj[s])
    {
        if(visited[u]==false)
            DFSRec(adj,u,visited);
    }
}
void DFS(vector<int>adj[],int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    DFSRec(adj,s,visited);
}
int main()
{
    int v=4;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);

    printAdjList(adj,v);

    BFS(adj,v,0);
    cout<<endl;
    BFS2(adj,v);

    cout<<count_connectingcmp_undirected(adj,v)<<endl;

    DFS(adj,v,0);
}