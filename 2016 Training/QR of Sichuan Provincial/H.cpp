//
//  Created by TaoSama on 2016-05-02
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL n, m;

LL get(LL l, LL r) {
    LL Q = 2 * MOD;
    return (l + 1 + r) % Q * ((r - l) % Q) % Q / 2;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d", &n, &m) == 2) {
        LL ans = n % MOD * (m % MOD) % MOD, t;
        m = min(n, m);
        for(t = 1; t <= m && t * t <= n; ++t)
            ans = (ans - n / t * t % MOD) % MOD;
        for(LL i = n / t; i >= n / m; --i) {
            LL l = n / (i + 1), r = min(n / i, m); //(l, r]
            ans = (ans - get(l, r) * i) % MOD;
        }
        printf("%I64d\n", (ans + MOD) % MOD);
    }
    return 0;
}
