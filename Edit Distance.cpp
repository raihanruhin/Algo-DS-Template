//EditDistance
/*
Parameter:	 given two vector (modify: given two string)
Return: 		min cost for edit distance with insert, delete, replace operation
Complexity:	O(m*n)
*/

int editDistance( vector<int>v1, vector<int>v2 )
{
    int m=v1.size(),n=v2.size();
    int C[m+5][n+5];

    C[0][0]=0;
    for(int i=1;i<=m;i++)
        C[i][0]=i;
    for(int j=1;j<=n;j++)
        C[0][j]=j;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            C[i][j] = min(min(C[i-1][j]+1, C[i][j-1]+1), C[i-1][j-1]+(v1[i-1]==v2[j-1] ? 0:1));
    return C[m][n];
}
