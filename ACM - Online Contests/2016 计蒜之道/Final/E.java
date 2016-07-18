import java.math.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger n = in.nextBigInteger();
        BigInteger three = BigInteger.valueOf(3);
        if(n.remainder(three).compareTo(BigInteger.ZERO) != 0) {
            System.out.println("-1");
        } else {
            BigInteger ans = n.divide(three);
            System.out.println(ans + " " + ans + " " + ans);
        }

        in.close();
    }


}
