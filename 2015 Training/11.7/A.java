import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        BigInteger dp[] = new BigInteger[305];
        BigInteger f[] = new BigInteger[305];
        dp[1] = dp[0] = f[1] = BigInteger.ONE;
        for(int i = 2; i <= 300; ++i) {
            f[i] = f[i - 1].multiply(BigInteger.valueOf(i));
            dp[i] = BigInteger.ZERO;
            for(int j = 0; j < i; ++j)
                dp[i] = dp[i].add(dp[j].multiply(dp[i - 1 - j]));
        }

        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int n = in.nextInt();
            if(n == 0) break;
            System.out.println(dp[n].multiply(f[n]));
        }
        in.close();
    }
}
