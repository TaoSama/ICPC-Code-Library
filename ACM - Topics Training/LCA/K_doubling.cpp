//
//  Created by TaoSama on 2015-11-10
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N << 1;

int n, q, w[N], dep[N], p[16][N];
int up[16][N], down[16][N], maxw[16][N], minw[16][N];

struct Edge {
    int v, nxt;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

void getMin(int& x, int y) {
    x = min(x, y);
}
void getMax(int& x, int y) {
    x = max(x, y);
}


void dfs(int u, int f, int d) {
    dep[u] = d; p[0][u] = f;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        getMax(up[0][v], w[u] - w[v]);
        getMax(down[0][v], w[v] - w[u]);
        getMin(minw[0][v], w[u]);
        getMax(maxw[0][v], w[u]);
        dfs(v, u, d + 1);
    }
}

void build() {
    dfs(1, -1, 0);
    for(int i = 0; i + 1 < 16; ++i) {
        for(int v = 1; v <= n; ++v) {
            if(p[i][v] < 0) {
                p[i + 1][v] = -1;
                up[i + 1][v] = up[i][v];
                down[i + 1][v] = down[i][v];
                maxw[i + 1][v] = maxw[i][v];
                minw[i + 1][v] = minw[i][v];
            } else {
                p[i + 1][v] = p[i][p[i][v]];
                up[i + 1][v] = max(max(up[i][v], up[i][p[i][v]]),
                                   maxw[i][p[i][v]] - minw[i][v]);
                down[i + 1][v] = max(max(down[i][v], down[i][p[i][v]]),
                                     maxw[i][v] - minw[i][p[i][v]]);
                maxw[i + 1][v] = max(maxw[i][v], maxw[i][p[i][v]]);
                minw[i + 1][v] = min(minw[i][v], minw[i][p[i][v]]);
            }
        }
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < 16; ++i)
        if(dep[v] - dep[u] >> i & 1)
            v = p[i][v];
    if(u == v) return u;
    for(int i = 16 - 1; ~i; --i) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

pair<int, int> getUp(int u, int to) {
    pair<int, int> ret(0, INF);
    for(int i = 0; i < 16; ++i) {
        if(dep[u] - dep[to] >> i & 1) {
            getMax(ret.first, max(up[i][u], maxw[i][u] - ret.second));
            getMin(ret.second, minw[i][u]);
            u = p[i][u];
        }
    }
    return ret;
}

pair<int, int> getDown(int u, int to) {
    pair<int, int> ret(0, 0);
    for(int i = 0; i < 16; ++i) {
        if(dep[u] - dep[to] >> i & 1) {
            getMax(ret.first, max(down[i][u], ret.second - minw[i][u]));
            getMax(ret.second, maxw[i][u]);
            u = p[i][u];
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", w + i);
            maxw[0][i] = minw[0][i] = w[i];
            up[0][i] = down[0][i] = 0;
        }
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        build();
        scanf("%d", &q);
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int _lca = lca(u, v);
//          prln(_lca);
            pair<int, int> l = getUp(u, _lca), r = getDown(v, _lca);
//          printf("%d %d %d %d\n", l.first, r.first, l.second , r.second);
            printf("%d\n", max(max(l.first, r.first), r.second - l.second));
        }
    }
    return 0;
}
