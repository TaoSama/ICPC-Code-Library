import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger dp[] = new BigInteger[10005];

        dp[3] = BigInteger.valueOf(4);
        dp[4] = BigInteger.valueOf(7);
        for(int i = 5; i <= 10000; ++i)
            dp[i] = dp[i - 1].add(dp[i - 2]);

        while(in.hasNextInt()) {
            int n = in.nextInt();
            System.out.println(dp[n]);
        }

        in.close();
    }
}
