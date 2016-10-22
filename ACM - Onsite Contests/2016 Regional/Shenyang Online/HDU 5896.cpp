//
//  Created by TaoSama on 2016-09-18
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
const int N = 4e4 + 10, INF = 0x3f3f3f3f, MOD = 1004535809;
const int G = 3, P = 1004535809;

typedef long long LL;
LL fact[N], finv[N], a[N];

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % P;
        x = x * x % P;
    }
    return ret;
}

LL A[N], B[N];
void rader(LL* y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void ntt(LL* y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        LL wn = quick(G, (P - 1) / h);
        if(op == -1) wn = quick(wn, P - 2);
        for(int j = 0; j < len; j += h) {
            LL w = 1;
            for(int k = j; k < j + h / 2; k++) {
                LL u = y[k];
                LL t = w * y[k + h / 2] % P;
                y[k] = (u + t) % P;
                y[k + h / 2] = (u - t + P) % P;
                w = w * wn % P;
            }
        }
    }
    if(op == -1) {
        LL inv = quick(len, P - 2);
        for(int i = 0; i < len; i++) y[i] = y[i] * inv % P;
    }
}

LL f[N], g[N];

void cdq(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);

    int len = 1;
    while(len <= r - l + 1) len <<= 1;
    for(int i = 0; i < len; i++) {
        A[i] = a[i];
        B[i] = l + i <= mid ? finv[l + i] * f[l + i] % P : 0;
    }
    ntt(A, len, 1);
    ntt(B, len, 1);
    for(int i = 0; i < len; i++) A[i] = A[i] * B[i] % P;
    ntt(A, len, -1);

//    printf("...%d %d\n", l, r);
//    for(int i = 0; i < len; ++i)
//      cout << i << ' ' << A[i] << endl;

    for(int i = mid + 1; i <= r; i++) {
        f[i] += fact[i - 1] * A[i - l - 1] % P;
        f[i] %= P;
    }
    cdq(mid + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = finv[0] = a[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % P;
        finv[i] = quick(fact[i], P - 2);
        a[i] = finv[i] * quick(i + 1, i - 1) % P;

        LL e = 1LL * i * (i - 1) / 2;
        g[i] = quick(2, e);
    }

    f[0] = 1;
    cdq(0, (int)2e4);

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        if(n <= 2) puts("0");
        else {
            LL ans = g[n] - f[n] + P;
            ans %= P;
            printf("%I64d\n", ans);
        }
    }


    return 0;
}
