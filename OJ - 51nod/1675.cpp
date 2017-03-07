//
//  Created by TaoSama on 2017-02-03
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

typedef long long LL;
int n, a[N], b[N], c[N], d[N];
vector<int> whc[N], whd[N];

const int C = N;
int notPrime[C], pc, g[C], p[C / 10], phi[C], mu[C];
vector<int> divisors[C];
void sieve() {
    phi[1] = mu[1] = 1;
    for(int i = 2; i < C; ++i) {
        if(!notPrime[i]) {
            p[pc++] = g[i] = i;
            phi[i] = i - 1; mu[i] = -1;
        }
        for(int j = 0; j < pc && i * p[j] < C; ++j) {
            int tmp = i * p[j];
            notPrime[tmp] = g[tmp] = p[j];
            if(i % p[j]) {
                phi[tmp] = phi[i] * (p[j] - 1);
                mu[tmp] = -mu[i];
            } else {
                phi[tmp] = phi[i] * p[j];
                mu[tmp] = 0;
                break;
            }
        }
    }

    for(int i = 1; i < C; ++i)
        for(int j = i; j < C; j += i)
            divisors[j].push_back(i);
}



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) {
        c[i] = a[b[i]];
        d[i] = b[a[i]];
        whc[c[i]].push_back(i);
        whd[d[i]].push_back(i);
    }

    sieve();

    LL ans = 0;
    vector<LL> cnt(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        if(!whc[i].size() || !whd[i].size()) continue;
        for(int p : whd[i])
            for(int d : divisors[p]) ++cnt[d];

        for(int p : whc[i])
            for(int d : divisors[p]) ans += mu[d] * cnt[d];

        for(int p : whd[i])
            for(int d : divisors[p]) --cnt[d];
    }

    cout << ans << endl;

    return 0;
}
