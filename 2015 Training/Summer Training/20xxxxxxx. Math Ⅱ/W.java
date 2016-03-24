import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger f[] = new BigInteger[1005];

        f[1] = BigInteger.ZERO;
        for(int i = 2; i <= 1000; ++i) {
            if(i % 2 == 1) f[i] = f[i - 1].shiftLeft(1).subtract(BigInteger.ONE);
            else f[i] = f[i - 1].shiftLeft(1).add(BigInteger.ONE);
        }

        while(in.hasNextInt()) {
            int n = in.nextInt();
            System.out.println(f[n]);
        }

        in.close();
    }
}

/*
int cnt = 0;
string s = "1";
cout << s << endl;
while(++cnt <= 20) {
    string t;
    for(auto c : s) {
        if(c == '0') t += "10";
        else t += "01";
    }
    int cur = 0;
    for(int i = 0; i < t.size(); i ++) {
        if(i + 1 < t.size() && t[i] == '0' && t[i] == t[i + 1])
            ++cur;
    }
    cout << cur << endl;
    cout << t << endl;
    s = t;
}
cout << endl;
int f[100] = {};
puts("0");
for(int i = 2; i <= 20; ++i) {
    if(i & 1) f[i] = 2 * f[i - 1] - 1;
    else f[i] = 2 * f[i - 1] + 1;
    printf("%d\n", f[i]);
}
*/
