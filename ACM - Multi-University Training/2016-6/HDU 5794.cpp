//
//  Created by TaoSama on 2016-08-04
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 110119;

typedef long long LL;
LL n, m, ox[N], oy[N];
int r;

LL g[1005][1005];
void DP() {
    memset(g, 0, sizeof(g));
    g[1][1] = 1;
    for(int j = 1; j <= n; j++) {
        for(int k = 1; k <= m; k++) {
            int ok = 1;
            for(int i = 1; i <= r; i++) {
                if(j == ox[i] && k == oy[i]) {
                    ok = 0;
                    break;
                }
            }
            //if(!ok) printf("NO\n");
            if(!ok) {
                g[j][k] = 0;
                continue;
            }
            g[j + 1][k + 2] += g[j][k];
            g[j + 2][k + 1] += g[j][k];
            g[j + 1][k + 2] %= MOD;
            g[j + 2][k + 1] %= MOD;
        }
    }
}

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL fact[N], invf[N];
void gao() {
    fact[0] = invf[0] = 1;
    for(int i = 1; i <= MOD; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = quick(fact[i], MOD - 2);
    }
}

LL C(int n, int m) {
    if(n < m) return 0;
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}

LL lucas(LL n, LL m) {
    if(m == 0) return 1;
    return C(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}

LL calc(LL x, LL y) {
    LL n = x + y + 1;
    if(n % 3) return -1;
    n /= 3;
    if(x < n || y < n) return -1;
    LL m = x - n;
    n--;
    return lucas(n, m);
}

int id[N];
LL f[N]; //to i, and let i be the first obstacle

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%I64d%I64d%d", &n, &m, &r) == 3) {
        for(int i = 1; i <= r; ++i) scanf("%I64d%I64d", ox + i, oy + i);

        for(int i = 1; i <= r; ++i) id[i] = i;
        sort(id + 1, id + 1 + r, [&](int x, int y) {
            return make_pair(ox[x], oy[x]) < make_pair(ox[y], oy[y]);
        });

        LL ans = calc(n, m);
        if(~ans) {
            for(int i = 1; i <= r; ++i) {
                int u = id[i];
                LL& cur = f[i];
                cur = calc(ox[u], oy[u]);
                if(cur == -1) continue;
                LL to = calc(n - ox[u] + 1, m - oy[u] + 1);
                if(to == -1) continue;
                for(int j = 1; j < i; ++j) {
                    if(f[j] == -1) continue;
                    int v = id[j];
                    if(ox[u] > ox[v] && oy[u] > oy[v]) {
                        LL tmp = calc(ox[u] - ox[v] + 1, oy[u] - oy[v] + 1);
                        if(tmp == -1) continue;
                        cur -= f[j] * tmp % MOD;
                        cur %= MOD;
                    }
                }
                ans = (ans - cur * to % MOD) % MOD;
            }
        } else ans = 0;
        ans = (ans + MOD) % MOD;
//        DP();
//        if(g[n][m] != ans) {
//            puts("WA");
//            pr(g[n][m]); prln(ans);
//        }
        static int kase = 0;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }

    return 0;
}

/*
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
  1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
  2   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
  3   0   1   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0
  4   0   0   0   2   0   0   1   0   0   0   0   0   0   0   0   0   0   0
  5   0   0   1   0   0   3   0   0   1   0   0   0   0   0   0   0   0   0
  6   0   0   0   0   3   0   0   4   0   0   1   0   0   0   0   0   0   0
  7   0   0   0   1   0   0   6   0   0   5   0   0   1   0   0   0   0   0
  8   0   0   0   0   0   4   0   0  10   0   0   6   0   0   1   0   0   0
  9   0   0   0   0   1   0   0  10   0   0  15   0   0   7   0   0   1   0
 10   0   0   0   0   0   0   5   0   0  20   0   0  21   0   0   8   0   0
 11   0   0   0   0   0   1   0   0  15   0   0  35   0   0  28   0   0   9
 12   0   0   0   0   0   0   0   6   0   0  35   0   0  56   0   0  36   0
 13   0   0   0   0   0   0   1   0   0  21   0   0  70   0   0  84   0   0
 14   0   0   0   0   0   0   0   0   7   0   0  56   0   0 126   0   0 120
 15   0   0   0   0   0   0   0   1   0   0  28   0   0 126   0   0 210   0
 16   0   0   0   0   0   0   0   0   0   8   0   0  84   0   0 252   0   0
 17   0   0   0   0   0   0   0   0   1   0   0  36   0   0 210   0   0 462
 18   0   0   0   0   0   0   0   0   0   0   9   0   0 120   0   0 462   0
*/
