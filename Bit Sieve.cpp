/// Bit Sieve, faster prime number calculation.
/// Tested on: Spoj TDPRIMES


int status[(MX/32)+2];
void bitSieve()
{
     int i, j, sqrtN,cnt=0;
     sqrtN = int( sqrt( MX ) );
     printf("2\n");
     cnt++;
     for( i = 3; i <= sqrtN; i += 2 )
        if(!(status[i>>5] & (1<<(i&31))))
        {
            if(!(cnt%100))  printf("%d\n",i);
            cnt++;
            for( j = i*i; j <= MX; j += (i<<1) )
                status[j>>5]= status[j>>5] | (1<<(j&31));
        }

     for(i=sqrtN+1;i<=MX;i+=2)
         if(!(status[i>>5] & (1<<(i&31))))
         {
             if(!(cnt%100))  printf("%d\n",i);
             cnt++;
         }
    return;
}
