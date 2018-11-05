import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[]) {
        final int MOD = 1000000007;
        Scanner in = new Scanner(System.in);
        int t = in.nextInt(), kase = 0;
        while(t-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();
            BigInteger ans = new BigInteger("" + m);
            int last = MOD;
            for(int i = 1; i <= n; ++i) {
                int x = in.nextInt();
                if(x > last) {
                    BigInteger lft = ans.mod(BigInteger.valueOf(last));
                    ans = ans.divide(BigInteger.valueOf(last));
                    ans = ans.multiply(BigInteger.valueOf(x));
                    ans = ans.add(lft);
                }
                last = x;
            }
            System.out.println("Case #" + ++kase + ": " + ans.mod(BigInteger.valueOf(MOD)));
        }
        in.close();
    }
}
