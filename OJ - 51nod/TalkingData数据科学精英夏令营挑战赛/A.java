import java.math.BigDecimal;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigDecimal a = in.nextBigDecimal();
        int n = in.nextInt();
        BigDecimal ans = a.pow(n);
        String s = ans.setScale(100, BigDecimal.ROUND_HALF_UP).toPlainString();
        //System.out.println(s);
        StringBuilder ss = new StringBuilder(s);
        int last = ss.length() - 1;
        while(last >= 0 && ss.charAt(last) == '0') --last;
        if(ss.charAt(last) == '.') --last;
        int first = 0;
        if(ss.charAt(first) == '0') ++first;
        System.out.println(ss.substring(first, last + 1));
        in.close();
    }

}
