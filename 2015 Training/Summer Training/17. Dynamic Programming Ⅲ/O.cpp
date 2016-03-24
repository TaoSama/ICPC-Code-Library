//
//  Created by TaoSama on 2015-08-13
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int need[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
char dp[110][3005][55], ans[55];

bool isLess(char *s, char *t) {
    int a = strlen(s), b = strlen(t);
    if(a != b) return a < b;
    return strcmp(s, t) < 0;
}

void gao(char *s, char *t, int k) {
    char tmp[55];
    memset(tmp, 0, sizeof tmp);
    strcpy(tmp, t);

    int len = strlen(tmp);
    if(tmp[0] == '0') tmp[0] = k + '0';
    else tmp[len] = k + '0';
    if(isLess(s, tmp)) strcpy(s, tmp);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        cin >> m;

        memset(dp, 0, sizeof dp);
        memset(ans, 0, sizeof ans);
        dp[0][0][0] = '0';
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dp[i][j][0] == 0) continue;
                for(int k = 0; k < 10; ++k) {
                    if(i + need[k] > n) continue;
                    gao(dp[i + need[k]][(j * 10 + k) % m], dp[i][j], k);
                }
            }
            if(i && isLess(ans, dp[i][0])) strcpy(ans, dp[i][0]);
        }
        cout << "Case " << ++kase << ": ";
        if(ans[0] == 0) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}

/*
Java BigInteger
import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int need[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
        BigInteger dp[][] = new BigInteger[105][3005];

        int kase = 0;
        while(in.hasNextInt()) {
            int n = in.nextInt();
            if(n == 0) break;
            int m = in.nextInt();

            BigInteger ans = BigInteger.valueOf(-1);
            for(int i = 0; i <= n; ++i)
                for(int j = 0; j < m; ++j)
                    dp[i][j] = BigInteger.valueOf(-1);
            dp[0][0] = BigInteger.ZERO;
            for(int i = 0; i <= n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(dp[i][j].compareTo(BigInteger.valueOf(-1)) == 0) continue;
                    for(int k = 0; k < 10; ++k) {
                        if(i + need[k] > n) continue;
                        BigInteger b = dp[i][j]
                                       .multiply(BigInteger.valueOf(10)).add(
                                           BigInteger.valueOf(k));
//                      System.out.println("b = " + b);
                        if(dp[i + need[k]][(j * 10 + k) % m].compareTo(b) == -1)
                            dp[i + need[k]][(j * 10 + k) % m] = b;

                    }
                }
                if(i >= 2 && ans.compareTo(dp[i][0]) == -1) ans = dp[i][0];
            }
            ++kase;
            System.out.println("Case " + kase + ": " + ans);
        }

        in.close();
    }
}
*/
