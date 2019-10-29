//LIS
/*
Parameter:	 the sequence vector
Return:		LIS of the sequence
Complexity:	O(nlogn)
*/

int LIS(vector<int>Sequence)
{
    int n=Sequence.size();
    int L[n+5],I[n+5],LisLength = 0;

    I[0] = -1e9;
    for(int i = 1; i <= n; i++ )
        I[i] = 1e9;

    for(int i = 0; i < n; i++ )
    {
        int low, high, mid;
        low = 0;
        high = LisLength;

        while( low <= high )
      {
            mid = ( low + high )>> 1;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }

        I[low] = Sequence[i];
        if( LisLength < low )
            LisLength = low;
    }
    return LisLength;
}
