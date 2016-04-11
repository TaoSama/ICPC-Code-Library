import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){		
		System.out.println("Case #1:");
		int cnt = 0;
		for(long i = 1l << 31; i <= 1l << 32; ++i){
			if((i >> 31 & 1) == 0 || (i & 1) == 0) continue;
			String s = "";
			for(int k = 0; k < 32; ++k)
				if((i >> k & 1) == 1) s += '1';
				else s += '0';
			boolean ok = true;
			int div[] = new int[11];
			for(int base = 2; base <= 10; ++base){
				BigInteger b = BigInteger.ZERO;
				for(int k = 0; k < 32; ++k) {
					b = b.multiply(BigInteger.valueOf(base));
					b = b.add(BigInteger.valueOf(s.charAt(k) - '0'));
				}
				if(b.isProbablePrime(3)){
					ok = false;
					break;
				}
				boolean have = false;
				for(int d = 2; d <= 100; ++d){
					if(b.mod(BigInteger.valueOf(d)).equals(BigInteger.ZERO)){
						have = true;
						div[base] = d;
						break;
					}
				}
				if(!have){
					ok = false;
					break;
				}
			}
			if(ok){
				System.out.print(s);
				for(int base = 2; base <= 10; ++base) System.out.print(" " + div[base]);
				System.out.println("");
				if(++cnt == 500) break;
			}
		}
	}
}
