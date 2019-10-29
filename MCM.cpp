/// MCM

int r[MX], c[MX], memo[MX][MX];
string s[MX][MX];

int func(int lft, int rgt)
{
    if(memo[lft][rgt]!=-1) return memo[lft][rgt];
    s[lft][rgt]="";
    if(rgt==lft)
    {
        stringstream ss;
        ss<<"A"<<lft+1;
        ss>>s[lft][rgt];
        return 0;
    }

    int ret=1e9; mid;
    for(int i=lft;i<rgt;i++)
    {
        int tmp = r[lft]*c[i]*c[rgt] + func(lft, i) + func(i+1, rgt);
        if(tmp<ret)
        {
            ret=tmp;
            mid=i;
        }
    }
    s[lft][rgt]="("+s[lft][mid]+" x "+s[mid+1][rgt]+")";
return memo[lft][rgt]=ret;
}

int main()
{
    int n,kk=1;
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)
            cin>>r[i]>>c[i];

        SET(memo);
        int tmp = func(0,n-1);
        cout<<"Case "<<kk++<<": "<<s[0][n-1]<<endl;
    }
return 0;
}
