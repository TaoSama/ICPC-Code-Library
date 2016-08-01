package test;

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
            int n = in.nextInt();
            BigInteger mul = BigInteger.ONE;
            for(int i = 0; i < n; ++i) mul = mul.multiply(BigInteger.valueOf(prime[i]));
            if(n == 2) {
                System.out.println(-1);
                continue;
            } else {
                for(int i = 0; i < n; ++i)
                    System.out.println(mul.divide(BigInteger.valueOf(prime[i])));
            }
        }
        in.close();
    }

}
