import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-- > 0){
            int n = in.nextInt();
            BigInteger fn = BigInteger.ONE;
            for(int i = 1; i <= n; ++i) fn = fn.multiply(BigInteger.valueOf(i));
            BigInteger ans = BigInteger.ZERO;
            for(int i = 1; i <= n; ++i){
                ans = ans.add(fn.divide(BigInteger.valueOf(i)));
            }
            System.out.println(ans + ".0");
        }
        in.close();
    }
}
