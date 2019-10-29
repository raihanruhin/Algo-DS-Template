//Hash_LOJ_1058
/*
Uses: where you canÅft take that long sized array, mapping of two or more value.
If u use map<pair,>, u will get TLE/MLE in that case.
SET all head value to -1
*/

int ans, inc, head[MX+2], next[MX+2];
int  getHash( int  x, int  y) // take the folding method HASH random change a bit. . .
{
    int  h = 0;
    h = ((x << 2) + (x >> 4)) ^ (y << 10);
    h = h% MX;
    h = h <0? h + MX: h;
    return  h;
}

void insrt(int a, int b)
{
    int h=getHash(a, b);
    for(int i=head[h]; i!=-1; i=next[i])
    {
        if(point[i].x==a && point[i].y==b)
        {
            ans+=point[i].cnt++;        //calculation depends on your problem
            return;
        }
    }

    point[inc].x=a;
    point[inc].y=b;
    point[inc].cnt=1;
    next[inc]=head[h];
    head[h]=inc++;
return;
}
