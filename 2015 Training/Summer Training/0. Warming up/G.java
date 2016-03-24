import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger f[] = new BigInteger[105];

        Scanner in = new Scanner(System.in);
        while(in.hasNextBigInteger()) {
            for(int i = 0; i < 3; ++i)
                f[i] = in.nextBigInteger();

            for(int i = 3; i < 100; ++i) {
                f[i] = BigInteger.ZERO;
                f[i] = f[i].add(f[i - 1]).add(f[i - 2]).add(f[i - 3]);
            }
            System.out.println(f[99]);
        }
        in.close();
    }
}
