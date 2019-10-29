KMP, O(N+M)
Tested on: LOJ 1255 Substring Frequency

void FailureFunction()
{
    int i=1,j=0;
    while(i<pl)
    {
        if(pattern[i]==pattern[j]) j++, failur[i]=j, i++;
        else if(j>0) j=failur[j-1];
        else failur[i]=0, i++;
    }
}
void KMPmatch()
{
    FailureFunction();
    int i=0,j=0;
    while(i<tl)
    {
        if(text[i]==pattern[j])
        {
            if(j==pl-1)   cnt++;  //a match found.
            i++, j++;
        }
        else if(j>0)   j=failur[j-1];
        else  i++;
    }
}

int main()
{
    int t,kk=1;
    cin>>t;
    while(t--)
    {
        cin>>text>>pattern;
        tl=text.length();
        pl=pattern.length();
        cnt=0;
        KMPmatch();
        cout<<"Case "<<kk++<<": "<<cnt<<endl;
    }
return 0;
}
