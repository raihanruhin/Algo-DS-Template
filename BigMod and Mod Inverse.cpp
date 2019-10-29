/// BigMod and Mod Inverse, O(long n)
/// Tested on: UVa 374

long long Bigmod(long long base, long long power)
{
    long long ret=1;
    while(power)
    {
        if(power & 1)
        	ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}
long long ModInverse(long long number)
{
    return Bigmod(number, MOD-2);
}

