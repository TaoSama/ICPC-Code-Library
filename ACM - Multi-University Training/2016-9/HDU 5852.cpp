//
//  Created by TaoSama on 2016-08-17
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e5 + 10;
typedef long long LL;

int n, k;
int up[N], dw[N];

LL fact[M], invf[M];

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

void gao() {
    fact[0] = invf[0] = 1;
    for(int i = 1; i < M; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = quick(fact[i], MOD - 2);
    }
}

LL C(int n, int m) {
    if(n < m) return 0;
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}

LL a[N][N];
LL det(int n) {
    LL ret = 1;
    int r = 0, c = 0;
    for(; r < n && c < n; ++r, ++c) {
        int maxR = r;       //row transform
        for(int i = r + 1; i < n; ++i)
            if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
        if(maxR != r) {
            ret = (-ret + MOD) % MOD;
            swap(a[maxR], a[r]);
        }

        if(!a[r][c]) return 0;

        LL inv = quick(a[r][c], MOD - 2);
        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            if(a[i][c]) {
                LL delta = a[i][c] * inv % MOD;
                for(int j = c; j < n; ++j) {
                    a[i][j] -= delta * a[r][j];
                    a[i][j] %= MOD;
                    if(a[i][j] < 0) a[i][j] += MOD;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) ret = ret * a[i][i] % MOD;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < k; ++i) scanf("%d", up + i);
        for(int i = 0; i < k; ++i) scanf("%d", dw + i);

        //up_i -> down_j
        for(int i = 0; i < k; ++i)
            for(int j = 0; j < k; ++j)
                a[i][j] = C(dw[j] - up[i] + n - 1, n - 1);

        LL ans = det(k);
        printf("%I64d\n", ans);
    }

    return 0;
}
