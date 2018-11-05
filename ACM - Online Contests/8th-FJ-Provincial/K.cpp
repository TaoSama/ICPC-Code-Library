
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
typedef long long LL;

LL d[N];
LL fact[N], finv[N];

LL quick(LL x, LL n){
    LL ret = 1;
    for(; n; n >>= 1){
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL C(int n, int m){
    if(n < m) return 0;
    return fact[n] * finv[m] % MOD * finv[n - m] % MOD;
}
int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % MOD;
    finv[N - 1] = quick(fact[N - 1], MOD - 2);
    for(int i = N - 2;  i >= 0; --i) finv[i] = finv[i + 1] * (i + 1) % MOD;
    d[0] = 1; d[1] = 0; d[2] = 1;
    for(int i = 3; i < N; ++i) d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;

    int t; scanf("%d", &t);
    while(t--){
        int n, k; scanf("%d%d", &n, &k);
        LL ans = 0;
        for(int i = k; i <= n; ++i) {
            ans += C(n, i) * d[n - i] % MOD;
            ans %= MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
