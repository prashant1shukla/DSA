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
void BFS_dist(vector<int>adj[],int v,int s,int dist[])
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                dist[v]=dist[u]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void printShortestPath(vector<int>adj[],int v)  //shortest path for undirected & unweighted graph BFS based approach.   
{
    int dist[v];
    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
    BFS_dist(adj,v,0,dist);
    for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
}
bool DFSRecUndirected(vector<int>adj[], int s, bool visited[], int parent)   //for undirected graphs.      
{
    visited[s]=true; 
    for(auto u:adj[s])
    {
        if(visited[u]==false)
        {
            if(DFSRecUndirected(adj, u, visited, s)==true)
                return true;
        }
        else if(!parent)
            return true;
    }
    return false;
}
bool cycleUndirected(vector<int>adj[], int v) //If there is an visited element and that is not the parent of the of the selected element then it is returned as the true. DFS based approach.
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            if(DFSRecUndirected(adj, i, visited, -1))
                return true;
        }
    } 
    return false;  
}
bool DFSRecDirected(vector<int>adj[],int s, bool visited[], bool recSt[]) 
{
    visited[s]=true;
    recSt[s]=true;
    for(int u: adj[s])
    {
        if(visited[u]==false&&DFSRecDirected(adj,u,visited,recSt))
            return true;
        else if(recSt[u]==true)
            return true;
    }
    recSt[s]=false;
    return false;
}
bool cycleDirected(vector<int>adj[], int v)  //for directed graphs-1
{
    bool visited[v];
    bool recSt[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++)
        recSt[i]=false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            if(DFSRecDirected(adj,i,visited,recSt))
                return true;
    }
    return false;
}
void topologicalSorting(vector<int>adj[],int v)
{
    vector<int>in_degree(v,0);
    for(int i=0;i<v;i++)    
    {
        for(auto x:adj[i])
            in_degree[x]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }
    while(q.size()!=0)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u])
        {
            if(--in_degree[x]==0)
                q.push(x);
        }
    }
}
bool topologicalSort(vector<int>adj[],int v) //cycle detection in directed graph using kahn's algo
{
    vector<int>in_degree(v,0);
    for(int i=0;i<v;i++)
    {
        for(int x:adj[i])
            in_degree[x]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }
    int count=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(int x:adj[u])
            if(--in_degree[x]==0)
                q.push(x);
        count++;
    }
    return (count!=v);
}
void DFStopo(vector<int>adj[],int u,stack<int>&st,bool visited[])
{
    visited[u]=false;
    for(int v:adj[u])
    {
        if(visited[v]==false)
            DFStopo(adj, v, st, visited);
    }
    st.push(u);
}
void topologicalSorting(vector<int>adj[], int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    stack<int>st;
    for(int u=0;u<v;u++)
    {
        if(visited[u]==false)
            DFStopo(adj, u, st, visited);
    }
    while(st.empty()==false)
    {
        int u=st.top();
        st.top();
        cout<<u<<" ";
    }
}

//Dijkstra's Algo-> for finding the shortest path: drawback is NEGATIVE CYCLE.
#define v 4
vector<int> dijkstra(int graph[v][v],int s)
{
    vector<int>dist(v,INT_MAX);
    vector<bool>fin(v,false);
    for(int i=0;i<v-1;i++)
    {
        int u=-1;
        for(int i=0;i<v-1;i++)
        {
            if(!fin[i]&&(u==-1||dist[i]<dist[u]))
            {
                u=i;
            }    
        }
        fin[u]=true;
        for(int i=0;i<v;i++)
        {
            dist[i]=min(dist[i]+graph[u][i],dist[i]);
        }
    }
}
int DijkstraPriorityQueue(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>>adj[n+1];
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minh;
    for(int i=0;i<times.size();i++)
    {
        int a=times[i][0];
        int b=times[i][1];
        int w=times[i][2];
        adj[a].push_back({b,w});
    }
    vector<int>ans(n+1,INT_MAX);
    ans[k]=0;
    minh.push({0,k});
    while(minh.size()!=0)
    {
        int curr=minh.top().second;
        minh.pop();
        for(auto x:adj[curr])
        {
            int next=x.first;
            int wt=x.second;
            if( ans[curr] + wt < ans[next] )
            {
                minh.push({ans[curr] + wt, next});
                ans[next] = ans[curr] + wt;
            }
        }
    }
    int p = 0; 
    for(int i=1; i<=n; i++)
    {
        if(ans[i] == INT_MAX)
            return -1;
        p = max(p,ans[i]);
    }
    return p;
}
int main()
{
    // int v=4;
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
    cout<<endl;

    printShortestPath(adj,v);
    cout<<endl;

    if(cycleUndirected(adj,v))
        cout<<"yaya"<<endl;
    else    
        cout<<"Noooo"<<endl;

    if(cycleDirected(adj,v))
        cout<<"yaya"<<endl;
    else    
        cout<<"Noooo"<<endl;

    topologicalSorting(adj,v);


    
}
