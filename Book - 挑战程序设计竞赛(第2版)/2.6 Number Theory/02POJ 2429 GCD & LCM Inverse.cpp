//
//  POJ 2429 GCD & LCM Inverse
//
//  Created by TaoSama on 2015-03-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

typedef long long LL;

LL gcd, lcm, factor[1005], cnt;
LL a, b, sq;

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

void dfs(LL s, LL val) {
    if(s >= cnt) {
        if(val > a && val <= sq)
            a = val;
        return;
    }
    dfs(s + 1, val);
    dfs(s + 1, val * factor[s]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> gcd >> lcm) {
        long long n = lcm / gcd;
        cnt = 0; factorize(n);
        sort(factor, factor + cnt);

        int j = 0;
        for(int i = 1; i < cnt; i++) {
            while(factor[i - 1] == factor[i] && i < cnt)
                factor[j] *= factor[i++];
            if(i < cnt) factor[++j] = factor[i];
        }
        cnt = j + 1; a = 1;
        sq = sqrt(n);
        dfs(0, 1);
        cout << a * gcd << ' ' << lcm / a << endl;
    }
    return 0;
}
