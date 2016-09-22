//
//  Created by TaoSama on 2016-09-22
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m;

typedef long long LL;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL fact[N], invf[N];
LL C(int n, int m) {
    if(n < m) return 0;
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}

LL calc(int n, int m) {
    return C(n + m - 1, m - 1);
}

LL solve(int lft, int x, int m) {
    LL ret = 0;
    for(int i = 0; i <= m; ++i) {
        if(lft - i * x < 0) continue;
        if(i & 1) ret -= C(m, i) * calc(lft - i * x, m) % MOD;
        else ret += C(m, i) * calc(lft - i * x, m) % MOD;
        ret %= MOD;
    }
    return (ret + MOD) % MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = invf[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = quick(fact[i], MOD - 2);
    }

    while(cin >> n >> m) {
        if(m == 1) {cout << "1\n"; continue;}

        LL ans = 0;
        for(int i = n / m + 1; i <= n; ++i) {
            ans += solve(n - i, i, m - 1);
        }
        ans = ans * m % MOD;
        cout << ans << endl;
    }

    return 0;
}
