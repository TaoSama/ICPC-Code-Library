//
//  Created by TaoSama on 2015-11-09
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

int n, q;

int dep[N], p[20][N], dp[N];

struct Edge {
    int v, c, nxt;
} edge[N << 1];
int head[N], cnt;

void add_edge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, c, head[u]};
    head[u] = cnt++;
}

void dfs(int u, int f, int d) {
    p[0][u] = f;
    dep[u] = d;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dp[v] = dp[u] + edge[i].c;
        dfs(v, u, d + 1);
    }
}

void init() {
    dfs(1, -1, 0);
    for(int i = 0; i + 1 < 18; ++i)
        for(int v = 1; v <= n; ++v)
            if(p[i][v] < 0) p[i + 1][v] = -1;
            else p[i + 1][v] = p[i][p[i][v]];
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < 18; ++i)
        if(dep[v] - dep[u] >> i & 1)
            v = p[i][v];
    if(u == v) return u;
    for(int i = 17; ~i; --i)
        if(p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}

int a, b, l;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
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
        init();
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int uv = dp[u] + dp[v] - 2 * dp[lca(u, v)];
            int ua = dp[u] + dp[a] - 2 * dp[lca(u, a)];
            int bv = dp[b] + dp[v] - 2 * dp[lca(b, v)];
            int ub = dp[u] + dp[b] - 2 * dp[lca(u, b)];
            int av = dp[a] + dp[v] - 2 * dp[lca(a, v)];
            printf("%d\n", max(0, uv - min(ua + bv, ub + av) - l));
        }
    }
    return 0;
}
