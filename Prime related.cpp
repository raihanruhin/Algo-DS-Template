vector<int>prime;
bool status[MX+2];

void PrimeGenerate(int n)
{
    int sq=sqrt(n);
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
            for(int j=i*i; j<=n; j+=(i<<1))
                status[j]=true;
    }

    status[0]=status[1]=true;
    for(int i=4;i<=n;i+=2) status[i]=true;

    prime.push_back(2);
    for(int i=3; i<=n; i+=2)
        if(!status[i])
            prime.push_back(i);
return;
}


vector<int> PrimeFactorize(int n)
{
    vector<int> primeDiv_pow;
    int pos=0;
    while(n>=prime[pos] && pos<pl)
    {
        int cnt=0;
        while(!(n%prime[pos]))
        {
            n/=prime[pos];
            cnt++;
        }
        if(cnt)
        {
            primeDiv_pow.push_back(prime[pos]);
            primeDiv_pow.push_back(cnt);
        }
        pos++;
    }
if(n!=1)
    {
        primeDiv_pow.push_back(n);
        primeDiv_pow.push_back(1);
    }
    return primeDiv_pow;
}


int numberOfDivisor(int n)
{
    vector<int>primeDiv_pow=PrimeFactorize(n);
    int vl=primeDiv_pow.size(),numOfDiv=1;
    for(int i=1;i<vl;i+=2)
        numOfDiv*=primeDiv_pow[i]+1;
    return numOfDiv;
}

int sumOfDivisor(int n)
{
    vector<int>primeDiv_pow=PrimeFactorize(n);
    int vl=primeDiv_pow.size(),sumOfDiv=1;
    for(int i=1;i<vl;i+=2)
        sumOfDiv*=(pow(primeDiv_pow[i-1], primeDiv_pow[i]+1)-1)/(primeDiv_pow[i-1]-1);
    return sumOfDiv;
}

int CoPrime(int n)
{
    vector<int>primeDiv_pow=PrimeFactorize(n);
    int vl=primeDiv_pow.size();

    for(int i=0;i<vl;i+=2)
    {
        n/=primeDiv_pow[i];
        n*=(primeDiv_pow[i]-1);
    }

return n;
}
