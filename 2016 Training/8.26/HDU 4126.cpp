//
//  Created by TaoSama on 2016-09-23
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
struct Edge {
    int u, v, c;
    bool operator<(const Edge& e) const {
        return c < e.c;
    }
} edges[N * N];

int g[N][N];
vector<int> G[N];

int p[N];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}
bool unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return false;
    p[x] = y;
    return true;
}

bool in[N][N];
int f[N][N], minv[N];

void dfs(int rt, int u, int fa) {
    minv[u] = INF;
    if(rt != fa) minv[u] = g[rt][u]; //not in MST
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(rt, v, u);
        minv[u] = min(minv[u], minv[v]);
        f[u][v] = f[v][u] = min(f[u][v], minv[v]);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        memset(g, 0x3f, sizeof g);
        for(int i = 0; i < m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            edges[i] = {u, v, c};
            g[u][v] = g[v][u] = c;
        }
        sort(edges, edges + m);

        int mst = 0, cnt = 0;
        memset(in, 0, sizeof in);
        for(int i = 0; i < n; ++i) p[i] = i, G[i].clear();
        for(int i = 0; i < m; ++i) {
            int u = edges[i].u, v = edges[i].v, c = edges[i].c;
            if(unite(u, v)) {
                mst += c;
                in[u][v] = in[v][u] = true;
                G[u].push_back(v);
                G[v].push_back(u);
                if(++cnt == n - 1) break;
            }
        }

        memset(f, 0x3f, sizeof f);
        for(int i = 0; i < n; ++i) dfs(i, i, -1);

        double ans = 0;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            if(!in[u][v]) ans += mst;
            else ans += mst - g[u][v] + min(c, f[u][v]);
        }
        printf("%.4f\n", ans / q);
    }

    return 0;
}
