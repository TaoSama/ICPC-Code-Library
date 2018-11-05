import java.util.*;
import java.io.*;
import java.math.*;


public class Main {
    public static class Frac {
        BigInteger p, q;
        Frac() {}
        Frac(BigInteger p, BigInteger q) {
            this.p = p;
            this.q = q;
            BigInteger gcd = this.p.gcd(this.q);
            // System.out.println("construct" + this.p + " " + this.q + " " + gcd);
            this.p = this.p.divide(gcd);
            this.q = this.q.divide(gcd);
            // System.out.println("after" + this.p + " " + this.q + " " + gcd);
        }
        Frac add(Frac f) {
            return new Frac(this.p.multiply(f.q).add(f.p.multiply(this.q)), this.q.multiply(f.q));
        }
        Frac sub(Frac f) {
            return new Frac(this.p.multiply(f.q).subtract(f.p.multiply(this.q)), this.q.multiply(f.q));
        }
        Frac mul(Frac f) {
            return new Frac(this.p.multiply(f.p), this.q.multiply(f.q)); 
        }
        Frac div(Frac f) {
            return new Frac(this.p.multiply(f.q), this.q.multiply(f.p)); 
        }
        void see() {
            System.out.println(p + "/" + q);
        }
    }
    public static void main(String args[]) {

        // Frac a = new Frac(BigInteger.valueOf(2), BigInteger.valueOf(4));
        // Frac b = new Frac(BigInteger.ZERO, BigInteger.valueOf(3));
        // Frac c = a.add(b);
        // c.see();

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        BigInteger threshold = BigInteger.valueOf(100000);
        while(t-- >0 ){
            BigInteger k = in.nextBigInteger();
            Frac A = new Frac(k.multiply(k), BigInteger.ONE);
            Frac x = new Frac(k, BigInteger.ONE), ans = new Frac(); 
            Frac w = new Frac(BigInteger.ONE, BigInteger.valueOf(3));
            for(int i = 1; i <= 13; ++i) {
                System.out.print(i + ": \n");
                // A.div(x.mul(x)).sub(x).see();
                // System.out.print("2: ");
                // A.div(x.mul(x)).sub(x).mul(w).see();
                // x.see();
                x = x.add(A.div(x.mul(x)).sub(x).mul(w));
                // System.out.print("3: ");
                // x.see();
                if(x.q.compareTo(threshold) <= 0) {
                    ans = x;
                }
            }
            ans.see();
        }
    }
}
