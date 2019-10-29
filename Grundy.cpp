//Grundy.  player can pick any pile and divide it into two unequal piles.

int grundy[mx];
int precalGrundy(int n)
{
    if(grundy[n]!=-1) return grundy[n];
    int hlf=(n+1)>>1;
    bool vis[mx]={0};
    for(int i=1;i<hlf;i++)
        vis[precalGrundy(i)^precalGrundy(n-i)]=1;
    int i=0;
    while(vis[i]) i++;
    return grundy[n]=i;
}

void precal()
{
    for(int i=0;i<mx;i++)   precalGrundy(i);
}
