import java.math.*;
import java.util.*;

public class Main {

    public static boolean isP(BigInteger b) {
        String s = b.toString();
        for(int i = 0; i < s.length() / 2; ++i) {
            if(s.charAt(i) != s.charAt(s.length() - i - 1))
                return false;
        }
        return true;
    }
    public static BigInteger getNxt(BigInteger b) {
        if(b.compareTo(BigInteger.valueOf(20)) < 0) return BigInteger.valueOf(9);

        String s = b.toString();
        StringBuilder to = new StringBuilder();
        to.append('1');
        for(int i = 0; i < s.length() / 2; ++i) to.append('0');
//        System.out.println("." + to);

        b = b.subtract(new BigInteger(to.toString()));
        StringBuilder t = new StringBuilder(b.toString());
        for(int i = 0; i < t.length() / 2; ++i)
            t.setCharAt(t.length() - i - 1, t.charAt(i));

//        System.out.println("o." + t.toString());
        return new BigInteger(t.toString());
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        int kase = 0;
        while(t-- > 0) {
            BigInteger n = in.nextBigInteger();
            List<BigInteger> l = new ArrayList<BigInteger>();
            while(true) {
                if(n.compareTo(BigInteger.valueOf(10)) < 0) {
                    l.add(n);
                    break;
                } else {
                    BigInteger ret = getNxt(n);
                    l.add(ret);
                    n = n.subtract(ret);
                }
            }
            System.out.printf("Case #%d:\n", ++kase);
            System.out.println(l.size());
            if(l.size() > 50) while(true) System.out.println("WA");
            for(int i = 0; i < l.size(); ++i)
                System.out.println(l.get(i));
        }
        in.close();
    }

}
