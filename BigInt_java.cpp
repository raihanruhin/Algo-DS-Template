/// Java BigInteger
/// Tested on: uva 623 - 500!


import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n;
        while(sc.hasNext())
        {
            n=sc.nextInt();
            BigInteger B = BigInteger.valueOf(1);
            for(int i=n; i>1; i--)
                B=B.multiply(BigInteger.valueOf(i));
            System.out.println(n+"!");
            System.out.println(B);
        }
    }
}
