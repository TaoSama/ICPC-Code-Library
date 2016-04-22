//
//  Created by TaoSama on 2015-11-11
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
const int N = 350 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int n, m;
struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int u, int v, int c): u(u), v(v), c(c) {}
    bool operator< (const Edge& rhs) const {
        return c < rhs.c;
    }
} edge[M];

int dis[N][N], vis[N], fa[N], cnt;

int lca(int u, int v) {
    memset(vis, false, sizeof vis);
    while(!vis[u] && u != fa[u]) vis[u] = true, u = fa[u];
    vis[u] = true;
    while(!vis[v] && v != fa[v]) v = fa[v];
    if(!vis[v]) return -1;
    return v;
}

void findCycle(int i) {
    int u = edge[i].u, v = edge[i].v;
    int _lca = lca(u, v);
//  prln(_lca);
    if(_lca == -1) return;

    int fu = fa[u], minv = INF, to = -1;
    while(u != _lca && u != fu) {
        if(dis[u][fu] < minv) minv = dis[u][fu], to = u;
        u = fu;
        fu = fa[fu];
    }
    int fv = fa[v];
    while(v != _lca && v != fv) {
        if(dis[v][fv] < minv) minv = dis[v][fv], to = v;
        v = fv;
        fv = fa[fv];
    }
    fa[to] = to; //delete the minimum edge in the cycle;
    --cnt;
}

int tmp[N];

void addEdge(int i) {
    int u = edge[i].u, v = edge[i].v;
    if(u == fa[u]) fa[u] = v;
    else if(v == fa[v]) fa[v] = u;
    else {
        int cc = 0;
        while(u != fa[u]) tmp[++cc] = u, u = fa[u];
        tmp[++cc] = u;
        for(int i = cc; i > 1; --i) fa[tmp[i]] = tmp[i - 1];
        fa[edge[i].u] = edge[i].v;
    }
    ++cnt;
}

int getMinEdge() {
    int ret = INF;
    for(int i = 1; i <= n; ++i)
        if(i != fa[i]) ret = min(ret, dis[i][fa[i]]);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            ++u; ++v;
            dis[u][v] = dis[v][u] = c;
            edge[i] = Edge(u, v, c);
        }
        sort(edge + 1, edge + 1 + m);

        cnt = 0;
        int ans = INF;
        for(int i = 1; i <= n; ++i) fa[i] = i;
        for(int i = 1; i <= m; ++i) {
            findCycle(i);
            addEdge(i);
            int minEdge = getMinEdge();
//          pr(cnt); prln(minEdge);
            if(cnt == n - 1) ans = min(ans, edge[i].c - minEdge);
        }
        printf("%d\n", ans);
    }
    return 0;
}
