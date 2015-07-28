import java.util.Scanner;
import java.math.BigInteger;

public class JULKA
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		BigInteger sum,more,two,klaudia,natalia;
		two = new BigInteger("2");	
		for(int i=10;i>0;i--)
		{
			sum = in.nextBigInteger();
			more = in.nextBigInteger();
			klaudia = sum.add(more).divide(two);
			natalia = sum.subtract(more).divide(two);			
			System.out.println(klaudia);
			System.out.println(natalia);
		}
	}
}
