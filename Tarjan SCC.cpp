//Tarjan SCC, O(V+E)
//scc is the total number of scc, sccrm[i] is the scc room number of node i where it belongs

void tarjan(int u)
{
    t++;
    vis[u]=1;
    tim[u]=t;
    lo[u]=t;
    stk.push(u);
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            tarjan(v);
            lo[u]=min(lo[u],lo[v]);
        }
        else if(vis[v]==1)
            lo[u]=min(lo[u], tim[v]);
    }

    if(lo[u]==tim[u])
    {
        scc++;
        int done;
        do
        {
            done = stk.top();
            stk.pop();
            sccrm[done]=scc;
            sccrmtot[scc]++;
            vis[done]=2;
        }
        while(done!=u);
    }
    return;
}
