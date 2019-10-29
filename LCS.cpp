// LCS

/*
parameter: 	given two vector
return:  	their longest common subsequence
complexity:	O(n*m)
*/

int LCS(vector<int>v1, vector<int>v2)
{
    int m=v1.size(),n=v2.size();
    int c[m+5][n+5];
    for(int i=0;i<=m;i++)
        c[i][0]=0;
    for(int i=0;i<=n;i++)
        c[0][i]=0;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(v1[i-1]==v2[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
return c[m][n];
}
