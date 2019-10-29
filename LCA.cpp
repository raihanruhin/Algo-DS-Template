//Lowest Common Ancestor (nlogn)
//Parent[i][0] is the parent of ith node
//Tested on: CodeForces 406D


int lca(int p, int q) //template from tc
{
    int tmp, log, i;
    if(depth[p] < depth[q])
        tmp = p, p = q, q = tmp;
    for(log = 1; 1 << log <= depth[p]; log++);
    log--;
    for(i = log; i >= 0; i--)
        if(depth[p] - (1 << i) >= depth[q])
            p = parent[p][i];
    if(p == q)
        return p;
    for(i = log; i >= 0; i--)
        if(parent[p][i]!=-1 && parent[p][i]!=parent[q][i])
            p = parent[p][i], q = parent[q][i];
    return parent[p][0];
}

void lca prepocess3
{
    for (int j = 1; 1 << j < n; j++)
        for (int i = 0; i < n; i++)
            if (parent[i][j - 1] != -1)
                parent[i][j]=parent[parent[i][j-1]][j-1];
    return;
}
