//
//  Created by TaoSama on 2016-04-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

typedef long long LL;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL g = a;
    if(!b) x = 1, y = 0;
    else {
        g = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
}

int n;
LL a[N], b[N], m[N], d;

// a_i*x = b_i mod m_i ==> x = b mod m
LL excrt(LL* a, LL* b, LL* m) {
    LL B = 0, M = 1;
    for(int i = 1; i <= n; ++i) {
        LL A = (M * a[i]) % m[i], c = (b[i] - B * a[i]) % m[i];
        LL x, y, g = exgcd(A, m[i], x, y);
        if(c % g) return -1;
        x = c / g * x % (m[i] / g);
        B += x * M;
        M *= m[i] / g;
        B %= M;
    }
    return (B % M + M) % M;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lld%lld%lld%lld", b + 1, b + 2, b + 3, &d) == 4 && d != -1) {
        n = 3;
        a[1] = a[2] = a[3] = 1;
        m[1] = 23, m[2] = 28, m[3] = 33;
        LL ans = excrt(a, b, m);
        ans = (ans - d + 21252) % 21252;
        if(ans == 0) ans = 21252;
        static int kase = 0;
        printf("Case %d: the next triple peak occurs in %lld days.\n", ++kase, ans);
    }
    return 0;
}
