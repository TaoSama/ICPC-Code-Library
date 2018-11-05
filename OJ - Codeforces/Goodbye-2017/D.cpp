
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int k;
LL pa, pb, invsum, invpa, invpb;

LL f[N][N];

LL dfs(int ab, int a) {
    if(ab + a >= k) return (ab + a + pa * invpb % MOD * invpb % MOD) % MOD;    
    LL& ret = f[ab][a];
    if(ret >= 0) return ret;
    ret = 0;
    if(a) ret = (ret + pb * dfs(ab + a, a)) % MOD;
    ret = (ret + pa * dfs(ab, a + 1)) % MOD;
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> k >> pa >> pb) {
        invsum = quick(pa + pb, MOD - 2);
        pa = pa * invsum % MOD;
        pb = pb * invsum % MOD;
        invpa = quick(pa, MOD - 2);
        invpb = quick(pb, MOD - 2);

        memset(f, -1, sizeof f);
        cout << invpa * dfs(0, 0) % MOD << endl;
    }
    return 0;
}
