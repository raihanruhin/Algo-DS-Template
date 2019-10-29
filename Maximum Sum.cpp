/// Maximum Sum, O(n^3)


int row[110][110], mat[110][110], n, m;

int func(int start, int end)
{
    int curnt=0, mx=-1e8;
    for(int i=1; i<=n; i++)
    {
        int j=row[i][end]-row[i][start-1];
        curnt+=j;
        if(curnt>mx) mx=curnt;
        if(curnt<0) curnt=0;
    }
    return mx;
}

int main()
{
    while(cin>>n)
    {
        for(int i=0; i<=n; i++)
            row[i][0]=0;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                cin>>mat[i][j];
                row[i][j]=row[i][j-1]+mat[i][j];
            }

        int temp=-1e8;
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++)
                temp=max(temp,func(i,j));

        cout<<temp<<endl;
    }
    return 0;
}
