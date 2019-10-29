//Histogram, O(n)
//Tested on SPOJ – HISTOGRA

int hist[MX], lft[MX], rgt[MX];
void Histogram(int n)
{
    stack<int>stk;
    stk.push(0), hist[0]=-1;
    for(int i=1;i<=n;i++)
    {
        while(hist[stk.top()]>=hist[i])  stk.pop();
        lft[i]=  stk.top()+1, stk.push(i);
    }
    while(!stk.empty())   stk.pop();
    stk.push(n+1), hist[n+1]=-1;
    for(int i=n;i>0;i--)
    {
        while(hist[stk.top()]>=hist[i])   stk.pop();
        rgt[i]=  stk.top()-1, stk.push(i);
    }
return;
}
