package test;mport java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){		
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- > 0){
			BigInteger q = in.nextBigInteger();
			BigInteger P = in.nextBigInteger();
			BigInteger ans = q.subtract(BigInteger.ONE);
			ans = ans.multiply(q.subtract(BigInteger.valueOf(2))).divide(BigInteger.valueOf(2));
			ans = ans.remainder(P);
			System.out.println(ans);
		}
	}
}
