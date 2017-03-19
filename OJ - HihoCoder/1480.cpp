//
//  Created by TaoSama on 2017-03-12
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL fact[N * 3];

LL inv(LL x) {
    LL ret = 1, n = MOD - 2;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = 1;
    for(int i = 1; i < N * 3; ++i) fact[i] = fact[i - 1] * i % MOD;

    int n, m; scanf("%d%d", &n, &m);
    if(n == 1) puts("1");
    else if(n == 2) {
        LL ans = fact[2 * m] * inv(fact[m]) % MOD * inv(fact[m]) % MOD * inv(m + 1) % MOD;
        printf("%lld\n",  ans);
    } else {
        LL ans = 2 * fact[3 * m] % MOD * inv(fact[m]) % MOD * inv(fact[m + 1]) % MOD * inv(fact[m + 2]) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}
