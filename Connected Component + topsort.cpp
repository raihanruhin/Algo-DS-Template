/*Connected Component, Topological Sort, O(V+E)
topSort is a vector that store topological sorting in reverse order
topSort and first dfs is not required for bi-directional graph
Tested on: Uva 11504 – Dominos*/

void dfs(int u)
{
    vis[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!vis[v])
            dfs(v);
    }
    topSort.push_back(u);
    return;
}

int connectedComponent(int n)
{
    CLR(vis);
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);

    CLR(vis);
    int cnt=0;
    for(int i=topSort.size()-1; i>=0; i--)
        if(!vis[topSort[i]])
        {
            cnt++;
            dfs(topSort[i]);
        }
    return cnt;
}
