//
//  Created by TaoSama on 2016-04-09
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

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
        y = mod_mul(x, x, n);
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

LL factor;

bool factorize(LL n, int c = 107) {
    if(n == 1)  return false;
    if(Miller_Rabin(n)) {
        factor = n;
        return true;
    }
    LL p = n;
    while(p >= n) p = Pollard_rho(p, c--);
    if(factorize(p, c)) return true;
    if(factorize(n / p, c)) return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    vector<pair<string, vector<LL> > > v;
    for(int i = 10; i < 1 << 16; ++i) {
        bitset<16> b(i);
        if(!b[0] || !b[15]) continue;
        string s = b.to_string();
        bool ok = true;
        vector<LL> div;
        for(int base = 2; base <= 10; ++base) {
            LL x = 0;
            for(int j = 0; j < 16; ++j) x = x * base + s[j] - '0';
            if(Miller_Rabin(x)) {
                ok = false;
                break;
            }
            factor = 0;
            factorize(x);
            div.push_back(factor);
        }
        if(ok) {
            v.push_back({s, div});
//            printf("%d: %s\n", i, s.c_str());
//            for(int base = 2; base <= 10; ++base) {
//                LL x = 0;
//                for(int j = 0; j < 16; ++j) x = x * base + s[j] - '0';
//                printf("%I64d ", x);
//            }
//            puts("");
//            for(LL x : div) printf("%I64d ", x); puts("");
        }
        if(v.size() == 50) break;
    }
    printf("Case #1:\n");
    for(auto p : v) {
        printf("%s", p.first.c_str());
        for(auto x : p.second) printf(" %I64d", x); puts("");
    }
    return 0;
}
