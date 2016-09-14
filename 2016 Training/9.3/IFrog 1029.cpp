//
//  Created by TaoSama on 2016-09-03
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL x;
LL factor[N], cnt;
int e[N];

LL mod_mul(LL a, LL b, LL mod) {
    LL ret = 0;
    while(b) {
        if(b & 1) ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}

LL mod_exp(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = mod_mul(ret, a, mod);
        a = mod_mul(a, a, mod);
        b >>= 1;
    }
    return ret;
}

bool check(LL a, LL n) {
    LL x = n - 1, y;
    int t = 0;
    while((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    x = mod_exp(a, x, n);

    for(int i = 1; i <= t; i++) {
        y = mod_exp(x, 2, n);
        if(y == 1 && x != 1 && x != n - 1) return true;
        x = y;
    }
    if(y != 1) return true;
    return false;
}

bool Miller_Rabin(LL n, int times = 20) {
    if(n == 2) return true;
    if(n == 1 || !(n & 1)) return false;

    for(int i = 1; i <= times; i++) {
        LL a = rand() % (n - 1) + 1;
        if(check(a, n)) return false;
    }
    return true;
}

LL Pollard_rho(LL n, int c) {
    LL i = 1, k = 2, x, y, d;
    y = x = rand() % n;
    while(true) {
        i++;
        x = (mod_mul(x, x, n) + c) % n;
        d = __gcd(y - x, n);
        if(d > 1 && d < n) return d;
        if(y == x) break;
        if(i == k) {
            y = x;
            k <<= 1;
        }
    }
    return n;
}


void factorize(LL n, int c = 107) {
    if(n == 1)  return;
    if(Miller_Rabin(n)) {
        factor[cnt++] = n;
        return;
    }
    LL p = n;
    while(p >= n) p = Pollard_rho(p, c--);
    factorize(p, c);
    factorize(n / p, c);
}

LL fact[N], invf[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = invf[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = mod_exp(fact[i], MOD - 2, MOD);
    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lld", &x);

        cnt = 0;
        factorize(x);

        map<LL, int> mp;
        for(int i = 0; i < cnt; ++i) ++mp[factor[i]];

        LL sum = fact[cnt];
        for(auto& p : mp) sum = sum * invf[p.second] % MOD;

        static int kase = 0;
        printf("Case #%d: %lld %lld\n", ++kase, cnt + 1, sum);

    }

    return 0;
}
