
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

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
LL A(int n, int m) {
    return fact[n] * finv[n - m] % MOD;
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
    for(int i = N - 2; i >= 0; --i) finv[i] = finv[i + 1] * (i + 1) % MOD;
    
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= i; ++j) {
            // cout << i << ' ' << j << ' ' << C(i,j) << ' ' << A(i,j) << endl;
        }
    }

    int a, b, c;
    while(cin >> a >> b >> c) {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
        auto calc = [&](int a, int b) {
            LL ret = 0;
            for(int i = 0; i <= a; ++i) {
                ret += C(a, i) * A(b, i) % MOD;
                ret %= MOD;
            }
            return ret;
        };
        cout << calc(a, b) * calc(a, c) % MOD * calc(b, c) % MOD << endl;
    }
    return 0;
}
