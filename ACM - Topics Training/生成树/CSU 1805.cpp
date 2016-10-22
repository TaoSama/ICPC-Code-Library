//
//  Created by TaoSama on 2016-09-07
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
const int N = 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL a[N][N], ans[N];
bool isFreeX[N];

LL gauss(int n, int m) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    LL ret = 1, neg = 0;

    int r = 1, c = 1;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; isFreeX[c] = true; continue;}
        if(p != r) {
            neg ^= 1;
            for(int i = c; i <= m; ++i) swap(a[p][i], a[r][i]);
        }

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            while(a[i][c]) {
                LL delta = a[i][c] / a[r][c];
                for(int j = c; j <= m; ++j) {
                    a[i][j] += MOD - delta * a[r][j] % MOD;
                    a[i][j] %= MOD;
                }
                if(!a[i][c]) break;
                neg ^= 1;
                for(int j = c; j <= m; ++j) swap(a[r][j], a[i][j]);
            }
        }
    }
    if(r != n) return 0;
    for(int i = 1; i < r; ++i) ret = ret * a[i][i] % MOD;
    if(neg) ret = (-ret + MOD) % MOD;
    return ret;
}

int A, B, C;
int deg[N];

bool check(int& x, int A) {
    if(x & 1) return false;
    x /= 2;
    return x >= 0 && x <= A;
}

const int M = 1e5 + 10;
LL fact[M], finv[M];

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL comb(int n, int m) {
    if(n < m) return 0;
    return fact[n] * finv[m] % MOD * finv[n - m] % MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = finv[0] = 1;
    for(int i = 1; i < M; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        finv[i] = quick(fact[i], MOD - 2);
    }

    while(scanf("%d%d%d", &A, &B, &C) == 3) {
        LL ans = 0;
        for(int x = 0; x <= A; ++x) { //x in-degrees from A; y from C, z from B
            int y = 2 * x + C - A;
            if(!check(y, C)) continue;
            int z = 2 * y + B - C;
            if(!check(z, B)) continue;
            if(x + B - z != A - x + z) continue; //check A

            deg[0] = x + B - z;
            deg[1] = y + A - x;
            deg[2] = z + C - y;
            for(int i = 0; i < 3; ++i) a[i][i] = deg[i];
            a[0][1] = -(A - x); a[0][2] = -z;
            a[1][0] = -x;  a[1][2] = -(C - y);
            a[2][0] = -(B - z); a[2][1] = -y;

            LL cur = comb(A, x) * comb(C, y) % MOD * comb(B, z) % MOD;

            //BEST Theorem
            cur = cur * gauss(3, 3) % MOD;
            cur = cur * deg[0] % MOD;
            for(int i = 0; i < 3; ++i) cur = cur * fact[deg[i] - 1] % MOD;
            ans = (ans + cur) % MOD;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
