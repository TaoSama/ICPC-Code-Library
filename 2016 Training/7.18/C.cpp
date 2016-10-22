import java.math.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-- > 0) {
            int n = in.nextInt();
            String a = in.next();
            String b = in.next();

            BigInteger ans = BigInteger.ONE;
            boolean ok = true;
            for(int i = 0; i < n; ++i) {
                if(!ok) continue;
                if(a.charAt(i) == '1' && b.charAt(i) == '1')
                    ans = ans.shiftLeft(1);
                else if(a.charAt(i) == '1' && b.charAt(i) == '0')
                    ok = false;
            }
            if(!ok) System.out.println("IMPOSSIBLE");
            else System.out.println(ans.remainder(BigInteger.valueOf(1000000007)));
        }

        in.close();
    }


}
