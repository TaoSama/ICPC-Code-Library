//
//  Created by TaoSama on 2015-09-24
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, a, b, l;

int cnt, head[N], pnt[N << 1], nxt[N << 1], cost[N << 1];
void add_edge(int u, int v, int c) {
    pnt[cnt] = v;
    cost[cnt] = c;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int dp[N], p[18][N], dep[N];

void dfs(int u, int f, int c, int d) {
    p[0][u] = f;
    dp[u] = c;
    dep[u] = d;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(v == f) continue;
        dfs(v, u, c + cost[i], d + 1);
    }
}

void gao() {
    dfs(1, -1, 0, 0);
    for(int i = 0; i + 1 < 18; ++i)
        for(int v = 1; v <= n; ++v)
            if(p[i][v] < 0) p[i + 1][v] = -1;
            else p[i + 1][v] = p[i][p[i][v]];
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < 18; ++i)
        if(dep[u] - dep[v] >> i & 1)
            v = p[i][v];
    if(u == v) return u;
    for(int i = 18 - 1; ~i; --i) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &q);
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        scanf("%d%d%d", &a, &b, &l);
        printf("Case #%d:\n", ++kase);

        gao();
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int uv = dp[u] + dp[v] - 2 * dp[lca(u, v)];
            int ua = dp[u] + dp[a] - 2 * dp[lca(u, a)];
            int bv = dp[b] + dp[v] - 2 * dp[lca(b, v)];
            int ub = dp[u] + dp[b] - 2 * dp[lca(u, b)];
            int av = dp[a] + dp[v] - 2 * dp[lca(a, v)];
            int ans = max(0, uv - min(ua + bv, ub + av) - l);
            printf("%d\n", ans);
        }
    }
    return 0;
}
