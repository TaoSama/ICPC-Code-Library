//
//  Created by TaoSama on 2016-08-12
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
const int G = 3, P = 998244353;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % P;
        x = x * x % P;
    }
    return ret;
}

LL A[N << 2], B[N << 2];
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

int n, a[N], f[N];
LL fact[N], invf[N], two[N], invt[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = two[0] = invf[0] = invt[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % P;
        two[i] = two[i - 1] * 2 % P;
        invf[i] = quick(fact[i], P - 2);
        invt[i] = quick(two[i], P - 2);
    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + n + 1, greater<int>());

        int len = 1;
        while(len <= n << 1) len <<= 1;
        for(int i = 0; i < len; ++i) {
            A[i] = i <= n ? two[n - i] * invf[i] % P : 0;
            B[i] = i >= 1 && i <= n ? a[i] * fact[i - 1] % P : 0;
        }
        reverse(B + 1, B + n + 1);

        ntt(A, len, 1);
        ntt(B, len, 1);
        for(int i = 0; i < len; ++i) A[i] = A[i] * B[i] % P;
        ntt(A, len, -1);

        for(int i = 1; i <= n; ++i) f[i] = invt[i] * invf[i - 1] % P * A[n - i + 1] % P;
        for(int i = 1; i <= n; ++i) if((f[i] += f[i - 1]) >= P) f[i] -= P;
        for(int i = 1; i <= n; ++i) printf("%d ", f[i]);
        puts("");
    }

    return 0;
}
