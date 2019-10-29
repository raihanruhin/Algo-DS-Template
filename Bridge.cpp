/// Bridge, bi-directional, O(V+E)
/// Tested on:
/// lightOJ 1026 - Critical Links

vector< pair<int, int> > bridge;
pair<int, int> pii;
int t, dis[MX], low[MX], parent[MX];

void findBridge(int u)
{
    low[u] = dis[u] = ++t;
    vis[u]=true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            parent[v]=u;
            findBridge(v);
            low[u]=min(low[u], low[v]);
            if(low[v]>dis[u])   //edge(u, v) is bridge
            {
                pii.first=u, pii.second=v;
                if(u>v)
                    swap(pii.first, pii.second); // if sort requires
                bridge.push_back(pii);
            }
        }
        else if(parent[u]!=v)
            low[u]=min(low[u], dis[v]);
    }
    return;
}

for(int i=0; i<node; i++)
    if(!vis[i])
        findBridge(i);
