
//combination, how many ways to choose r from n numbers

for(int i=1; i<=100; i++)
{
    nCr[i][0]=nCr[i][i]=1;
    for(int j=1; j<i; j++)
        nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
}

// how many ways to put n different ball into r different box.
//  empty box is not allowed. (Loj 1326)

nCr[0][0]=nCr[0][1]=nCr[1][1]=ans[1]=1;
for(int i=2; i<=100; i++)
    for(int j=1; j<=i; j++)
        nCr[i][j]=nCr[i-1][j-1]*j+nCr[i-1][j]*j;


