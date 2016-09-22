//
//  Created by TaoSama on 2016-08-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdio.h>
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 5e4 + 10;

typedef long long LL;
int n, m;
LL f[N][N][N], g[N], h[N];
//x倍数的i->j的路径数, x的倍数的路径数, x的路径数

int u[M], v[M], c[M];
vector<int> G[N], topo;

vector<int> divisors[N];
void gao() {
    for(int i = 1; i < N; ++i)
        for(int j = i; j < N; j += i)
            divisors[j].push_back(i);
}

#define rep(i, a, b) for(int i = a; i <= b; ++i)

LL calc(int div) {
    LL sum = 0;
    vector<LL> dp(n + 1, 0);
    for(int i = 0; i < topo.size(); ++i) {
        int u = topo[i];
        sum = (sum + dp[u]) % MOD;
        for(int j = i + 1; j < topo.size(); ++j) {
            int v = topo[j];
            dp[v] += f[div][u][v] * (1 + dp[u]);
            dp[v] %= MOD;
        }
    }
    return sum;
}

LL solve() {
    for(int i = 100; i; --i) {
        h[i] = g[i];
        for(int j = i + i; j <= 100; j += i) h[i] -= h[j];
        h[i] = (h[i] % MOD + MOD) % MOD;
    }
    return h[1];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

    scanf("%d%d", &n, &m);
    vector<int> in(n + 1, 0);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", u + i, v + i, c + i);
        G[u[i]].push_back(v[i]); ++in[v[i]];
        for(int div : divisors[c[i]]) ++f[div][u[i]][v[i]];
    }

    for(int i = 1; i <= n; ++i) if(!in[i]) topo.push_back(i);
    for(int i = 0; i < topo.size(); ++i) {
        int u = topo[i];
        for(int v : G[u]) if(--in[v] == 0) topo.push_back(v);
    }

    for(int i = 1; i <= 100; ++i) g[i] = calc(i);
    printf("%lld\n", solve());

    int q; scanf("%d", &q);
    while(q--) {
        int x, y; scanf("%d%d", &x, &y);

        vector<int> affected;
        for(int div : divisors[c[x]]) {
            --f[div][u[x]][v[x]];
            affected.push_back(div);
        }
        c[x] = y;
        for(int div : divisors[c[x]]) {
            ++f[div][u[x]][v[x]];
            affected.push_back(div);
        }
        sort(affected.begin(), affected.end());
        affected.resize(unique(affected.begin(), affected.end()) - affected.begin());

        for(int div : affected) g[div] = calc(div);
        printf("%lld\n", solve());
    }

    return 0;
}
