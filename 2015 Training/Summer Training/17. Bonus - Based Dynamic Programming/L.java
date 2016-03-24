import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger dp[][][] = new BigInteger[65][65][65];

        dp[0][0][0] = BigInteger.ONE;
        for(int i = 1; i <= 60; ++i) {
            for(int j = 0; j <= i; ++j) {
                for(int k = 0; k <= j; ++k) {
                    dp[i][j][k] = BigInteger.ZERO;
                    if(i > j) dp[i][j][k] = dp[i][j][k].add(dp[i - 1][j][k]);
                    if(j > k) dp[i][j][k] = dp[i][j][k].add(dp[i][j - 1][k]);
                    if(k > 0) dp[i][j][k] = dp[i][j][k].add(dp[i][j][k - 1]);
                }
            }
        }

        Scanner in = new Scanner(System.in);
        while(in.hasNextBigInteger()) {
            int n = in.nextInt();
            System.out.println(dp[n][n][n]);
            System.out.println();
        }

        in.close();
    }
}
