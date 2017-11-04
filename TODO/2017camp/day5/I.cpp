//
//  Created by TaoSama on 2017-02-17
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
vector<int> wh[N];

int notPrime[N], mu[N];
vector<int> primes, divisors[N];
void gao() {
    mu[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!notPrime[i]) {
            mu[i] = -1;
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            int x = i * primes[j];
            notPrime[x] = true, mu[x] = -mu[i];
            if(i % primes[j] == 0) {mu[x] = 0; break;}
        }
    }
//    for(int i = 1; i <= 10; ++i) printf("mu[%d] = %d\n", i, mu[i]);
    for(int i = 1; i < N; ++i) {
        if(mu[i] == 0) continue;
        for(int j = i; j < N; j += i) divisors[j].push_back(i);
    }
}

int getCoprime(int l, int r, int x) {
    int ret = 0;
    for(int div : divisors[x])
        ret += mu[div] *
               (upper_bound(wh[div].begin(), wh[div].end(), r) - lower_bound(wh[div].begin(), wh[div].end(), l));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        for(int div : divisors[x]) wh[div].push_back(i);
    }

    while(q--) {
        int L, R, x; scanf("%d%d%d", &L, &R, &x);
        int coprimes = getCoprime(L, R, x);
        if(!coprimes) puts("-1");
        else {
            int l = L, r = R, ans = -1;
            while(l <= r) {
                int m = l + r >> 1;
                if(getCoprime(L, m, x) >= coprimes) ans = m, r = m - 1;
                else l = m + 1;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
