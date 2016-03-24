import java.util.*;
import java.math.BigInteger;

//g[i] = min{f[k]*2 + g[n-k]} 1<=k<=n
public class Main {
    public static void main(String[] args) {
        BigInteger dp[] = new BigInteger[10005];
        dp[0] = BigInteger.ZERO;
        BigInteger add = BigInteger.ONE;
        for(int i = 1, j = 1, k = 1; i <= 10000; ++i) {
            if(j > k) {
                add = add.shiftLeft(1);
                j = 1; ++k;
            }
            ++j;
            dp[i] = dp[i - 1].add(add);
        }

        Scanner in = new Scanner(System.in);
        while(in.hasNextInt()) {
            int n = in.nextInt();
            System.out.println(dp[n]);
        }

        in.close();
    }
}
