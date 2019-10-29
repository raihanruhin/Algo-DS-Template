RMQ with Sparse Table, O(nlogn)
Tested on LOJ 1082

int M[MX][20], A[MX], N;	//A=array, MX=array size

void sparse_table()
{
    for (int i = 0; i < N; i++)     M[i][0] = A[i];
    for (int j = 1; 1 << j <= N; j++)
        for (int i = 0; i + (1 << j) - 1 < N; i++)
            if (M[i][j - 1] < M[i + (1 << (j - 1))][j - 1])     M[i][j] = M[i][j - 1];
            else    M[i][j] = M[i + (1 << (j - 1))][j - 1];
return;
}

int mn(int i, int j)	//left and right index, to find min of the array segment
{
    int k = log(j - i + 1)/log(2);
    int pk=pow(2,k);
    return min(M[i][k],M[j-pk+1][k]);
}

