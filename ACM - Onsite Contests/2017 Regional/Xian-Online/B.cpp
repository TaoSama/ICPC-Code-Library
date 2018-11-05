
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL p, q, k;
LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    LL twoinv = quick(2, MOD - 2) % MOD;
    while(t--) {
        cin >> p >> q >> k;
        LL pinv = quick(p, MOD - 2);
        LL prob = q * pinv % MOD;
        LL nprob = (p - q) * pinv % MOD;
        LL ans = (1 + quick(nprob - prob + MOD, k)) * twoinv % MOD;
        cout << ans << endl;
    }
    return 0;
}
