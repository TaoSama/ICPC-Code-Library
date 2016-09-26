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

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int m = 0;
        memset(g, 0x3f, sizeof g);
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= n - i; ++j) {
                int c; scanf("%d", &c);
                g[i][i + j] = g[i + j][i] = c;
//                pr(i); pr(i+j); prln(c);
                edges[m++] = {i, i + j, c};
            }
        }
        sort(edges, edges + m);

        int mst = 0, cnt = 0;
        for(int i = 1; i <= n; ++i) p[i] = i, G[i].clear();
        for(int i = 0; i < m; ++i) {
            int u = edges[i].u, v = edges[i].v, c = edges[i].c;
            if(unite(u, v)) {
                mst += c;
                G[u].push_back(v);
                G[v].push_back(u);
                if(++cnt == n - 1) break;
            }
        }

        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; ++i) dfs(i, i, -1);

        int ans = 0;
        for(int u = 1; u <= n; ++u)
            for(int v : G[u]) ans += f[u][v] == g[u][v];

        ans = n - 1 - ans / 2;
        printf("%d\n", ans);
    }

    return 0;
}
