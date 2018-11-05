
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
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
LL fact[N], finv[N];

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL C(int n, int m) {
    return fact[n] * finv[m] % MOD * finv[n - m] % MOD;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % MOD;
    finv[N - 1] = quick(fact[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i) finv[i] = finv[i + 1] * (i + 1) % MOD;
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        if(n < m) swap(n, m);
        printf("%lld\n", C(n, m));
    }
    return 0;
}
