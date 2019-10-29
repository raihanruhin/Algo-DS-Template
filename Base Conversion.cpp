/// Base Conversion

long long toDecimal(string s, int baseFrom)
{
    int cnt=0;
    long long res=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if ( s[i] > 47 && s[i] < 58 ) res+= (pow(baseFrom,cnt)*(s[i]-'0'));
        else  res+= (pow(baseFrom,cnt)*(s[i]-55));
        cnt++;
    }
    return res;
}

string deciamlTo(long long num, int baseTo)
{
    string s="";
    while(num)
    {
        int tmp=num%baseTo;
        if(tmp<10)   s+=tmp+'0';
        else   s+= char (tmp+55);
        num/=baseTo;
    }
    if(s=="")    return "0";
    reverse(s.begin(), s.end());
    return s;
}
