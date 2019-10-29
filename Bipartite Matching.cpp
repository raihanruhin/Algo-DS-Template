/// Bipartite Matching, O(N^2*E)
/// Tested on LOJ 1201

vector<int>adj[MX];
int matchR[MX];
bool vis[MX];

bool bpm(int u)
{
    int vl=adj[u].size();
    for (int i = 0; i < vl; i++)
    {
        int v=adj[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v]))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(int n)
{
    SET(matchR);
    int cnt = 0;
    for (int i = 1; i <=n ; i++)
    {
        CLR(vis);
        if(bpm(i)) cnt++;
    }
    return cnt;
}
