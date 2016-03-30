//
//  Created by TaoSama on 2015-12-04
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
const int N = 5e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * N;

int n, m;

int par[N];
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

struct Edge {
    int u, v, c;
    bool operator< (const Edge& e) const {
        return c < e.c;
    }
} edge[M];

bool vis[M];
int g[N][N];

int kruskal() {
    int ret = 0, cnt = 0;
    sort(edge + 1, edge + 1 + m);
    for(int i = 1; i <= n; ++i) par[i] = i;
    memset(g, 0, sizeof g);
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= m; ++i) {
        Edge& e = edge[i];
        int u = find(e.u), v = find(e.v);
        if(u == v) continue;
        par[v] = u; vis[i] = true;
        g[e.u][e.v] = g[e.v][e.u] = e.c;
        ret += e.c;
        if(++cnt == n - 1) break;
    }
    return ret;
}

int dep[N], p[N];

void dfs(int u, int f, int d) {
    dep[u] = d; p[u] = f;
    for(int v = 1; v <= n; ++v) {
        if(!g[u][v] || v == f) continue;
        dfs(v, u, d + 1);
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    while(dep[u] < dep[v]) v = p[v];
    while(u != v) u = p[u], v = p[v];
    return u;
}

pair<int, int> tryToDel(int u, int v, int c) {
    int _lca = lca(u, v);
    pair<int, int> ret(0, 0);
    while(u != _lca) {
        int f = p[u];
        if(c == g[f][u]) {
            ret.first += g[f][u];
            ret.second++;
            g[f][u] = g[u][f] = 0;
        }
        u = f;
    }
    while(v != _lca) {
        int f = p[v];
        if(c == g[f][v]) {
            ret.first += g[f][v];
            ret.second++;
            g[f][v] = g[v][f] = 0;
        }
        v = f;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            edge[i] = (Edge) {u, v, c};
        }
        int ans = kruskal(), cnt = n - 1;
        dfs(1, -1, 0);
        for(int i = 1; i <= m; ++i) {
            if(vis[i]) continue;
            Edge &e = edge[i];
            pair<int, int> tmp = tryToDel(e.u, e.v, e.c);
            ans -= tmp.first, cnt -= tmp.second;
        }
        printf("%d %d\n", cnt, ans);
    }
    return 0;
}
