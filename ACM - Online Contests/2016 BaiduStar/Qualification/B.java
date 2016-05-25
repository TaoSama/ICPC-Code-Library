import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger f[] = new BigInteger[205];
        f[1] = f[0] = BigInteger.ONE;
        for(int i = 2; i <= 200; ++i)
            f[i] = f[i - 1].add(f[i - 2]);
        while(in.hasNext()) {
            int n = in.nextInt();
            System.out.println(f[n]);
        }
    }
}
