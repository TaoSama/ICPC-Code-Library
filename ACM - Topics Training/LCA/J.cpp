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

int n, m, q;

struct RawEdge {
    int u, v, c;
    bool operator<(const RawEdge& rhs) const {
        return c < rhs.c;
    }
};
vector<RawEdge> E;

struct Edge {
    int v, c, nxt;
} edge[N];
int head[N], cnt;

void add_edge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, c, head[u]};
    head[u] = cnt++;
}

int par[N];
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void kruskal() {
    for(int i = 1; i <= n; ++i) par[i] = i;
    sort(E.begin(), E.end());
    cnt = 0; memset(head, -1, sizeof head);
    int num = 0;
    for(auto &e : E) {
        int u = find(e.u), v = find(e.v);
        if(u == v) continue;
        par[u] = v;
//      pr(e.u); pr(e.v); prln(e.c);
        add_edge(e.u, e.v, e.c);
        add_edge(e.v, e.u, e.c);
        if(++num == n - 1) break;
    }
}

int dep[N], p[20][N], maxv[20][N];

void dfs(int u, int f, int c, int d) {
    dep[u] = d;
    p[0][u] = f; maxv[0][u] = c;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dfs(v, u, edge[i].c, d + 1);
    }
}

void build() {
    dfs(1, -1, 0, 0);
    for(int i = 0; i + 1 < 18; ++i) {
        for(int v = 1; v <= n; ++v) {
            if(p[i][v] < 0) p[i + 1][v] = -1;
            else p[i + 1][v] = p[i][p[i][v]];
            maxv[i + 1][v] = max(maxv[i][v], maxv[i][p[i][v]]);
        }
    }
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

int get(int u, int to) {
    int ret = 0;
    for(int i = 0; i < 18; ++i)
        if(dep[u] - dep[to] >> i & 1)
            ret = max(ret, maxv[i][u]), u = p[i][u];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        E.clear();
        while(m--) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            E.push_back((RawEdge) {u, v, c});
        }
        kruskal();
        build();
        scanf("%d", &q);
        if(kase++) puts("");
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int _lca = lca(u, v);
//          prln(_lca);
            printf("%d\n", max(get(u, _lca), get(v, _lca)));
        }
    }
    return 0;
}
