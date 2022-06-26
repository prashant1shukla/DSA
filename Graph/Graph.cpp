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
}