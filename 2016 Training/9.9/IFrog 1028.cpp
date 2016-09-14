//
//  Created by TaoSama on 2016-09-09
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

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

const LL invTwo = quick(2, MOD - 2);

void fwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtXor(a, h);
    fwtXor(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = (x1 - x2 + MOD) % MOD;
    }
}

void ifwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x1-x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 + y2) * invTwo % MOD;
        a[i + h] = (y1 - y2 + MOD) * invTwo % MOD;
    }
    ifwtXor(a, h);
    ifwtXor(a + h, h);
}

void fwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtAnd(a, h);
    fwtAnd(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = x2;
    }
}

void ifwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 - y2 + MOD) % MOD;
        a[i + h] = y2;
    }
    ifwtAnd(a, h);
    ifwtAnd(a + h, h);
}

void fwtOr(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtOr(a, h);
    fwtOr(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = x1;
        a[i + h] = (x2 + x1) % MOD;
    }
}

void ifwtOr(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1
        // y2=x2+x1
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = y1;
        a[i + h] = (y2 - y1 + MOD) % MOD;
    }
    ifwtOr(a, h);
    ifwtOr(a + h, h);
}

int n, op;
const int C = 1 << 20;
LL a[N], cnt[C + 10];

int gao() {
    for(int i = C; ~i; --i) if(cnt[i]) return i;
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &op);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
            ++cnt[a[i]];
        }

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(op == 1) {
            fwtAnd(cnt, C);
            for(int i = 0; i < C; ++i) cnt[i] = cnt[i] * cnt[i] % MOD;
            ifwtAnd(cnt, C);
            for(int i = 1; i <= n; ++i) --cnt[a[i] & a[i]];
            printf("%d\n", gao());
        } else if(op == 2) {
            fwtXor(cnt, C);
            for(int i = 0; i < C; ++i) cnt[i] = cnt[i] * cnt[i] % MOD;
            ifwtXor(cnt, C);
            for(int i = 1; i <= n; ++i) --cnt[a[i] ^ a[i]];
            printf("%d\n", gao());
        } else {
            fwtOr(cnt, C);
            for(int i = 0; i < C; ++i) cnt[i] = cnt[i] * cnt[i] % MOD;
            ifwtOr(cnt, C);
            for(int i = 1; i <= n; ++i) --cnt[a[i] | a[i]];
            printf("%d\n", gao());
        }
    }

    return 0;
}
