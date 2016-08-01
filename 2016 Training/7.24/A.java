import java.math.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
                        109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                        179, 181, 191, 193, 197, 199, 211, 223, 227, 229
                      };

        int t = 1;
        while(t-- > 0) {
            BigInteger n = in.nextBigInteger();
            if(n.compareTo(BigInteger.valueOf(Byte.MIN_VALUE)) >= 0 &&
            		n.compareTo(BigInteger.valueOf(Byte.MAX_VALUE)) <= 0)
            	System.out.println("byte");
            else if(n.compareTo(BigInteger.valueOf(Short.MIN_VALUE)) >= 0 &&
            		n.compareTo(BigInteger.valueOf(Short.MAX_VALUE)) <= 0)
            	System.out.println("short");
            else if(n.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) >= 0 &&
            		n.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) <= 0)
            	System.out.println("int");
            else if(n.compareTo(BigInteger.valueOf(Long.MIN_VALUE)) >= 0 &&
            		n.compareTo(BigInteger.valueOf(Long.MAX_VALUE)) <= 0)
            	System.out.println("long");
            else System.out.println("BigInteger");
        }

        in.close();
    }

}
