/// BIT (2D), O(nlogn)
/// Tested on spoj MATSUM

int tree[MX][MX];

void update(int x , int y , int val)
{
    int y1;
    while (x <= MX)
    {
        y1 = y;
        while (y1 <= MX)
        {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
    return;
}

int read(int x , int y )
{
    int y1, ret=0;
    while (x)
    {
        y1 = y;
        while (y1)
        {
            ret+=tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return ret;
}
