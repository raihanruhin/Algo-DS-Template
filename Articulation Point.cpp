/// Articulation Point, bi-directional, O(V+E)
/// Tested on: lightOJ 1063 - Ant Hills

int t, dis[MX], low[MX], parent[MX];
bool isArti[MX];

void findAP(int u, int root)
{
    low[u] = dis[u] = ++t;
    vis[u]=true;
    int children=0;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            children++;
            parent[v]=u;
            findAP(v, root);
            low[u]=min(low[u], low[v]);

            if(u==root && children>1)
                isArti[u]=true;     //special check for root
            else if(u!=root && low[v]>=dis[u])
                isArti[u]=true;
        }
        else if(parent[u]!=v)
            low[u]=min(low[u], dis[v]);
    }
    return;
}

for(int i=1; i<=n; i++)
    if(!vis[i])
        findAP(i, i);
