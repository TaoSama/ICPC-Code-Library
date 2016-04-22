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

struct Edge {
    int v, c, nxt;
};

struct HLD {
    Edge edge[N << 1];
    int head[N], cnt;
    int fa[N], top[N], dep[N], sz[N], dp[N], son[N];

    void init() {
        cnt = 0;
        memset(head, -1, sizeof head);
    }
    void add_edge(int u, int v, int c) {
        edge[cnt] = (Edge) {v, c, head[u]};
        head[u] = cnt++;
    }

    void dfs1(int u, int f, int d) {
        fa[u] = f; dep[u] = d;
        sz[u] = 1; son[u] = 0;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(v == f) continue;
            dp[v] = dp[u] + edge[i].c;
            dfs1(v, u, d + 1);
            if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
            sz[u] += sz[v];
        }
    }

    void dfs2(int u, int tp) {
        top[u] = tp;
        if(son[u]) dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
    }

    int lca(int u, int v) {
        while(top[u] != top[v]) {
            if(dep[top[u]] > dep[top[v]])
                u = fa[top[u]];
            else v = fa[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }
} hld;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        hld.init();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            hld.add_edge(u, v, 1);
            hld.add_edge(v, u, -1);
        }
        hld.build();
        scanf("%d", &q);
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int _lca = hld.lca(u, v);
            int dpu = hld.dp[u] - hld.dp[_lca];
            int dpv = hld.dp[v] - hld.dp[_lca];
            int depu = hld.dep[u] - hld.dep[_lca];
            int depv = hld.dep[v] - hld.dep[_lca];
            if(dpu == -depu && dpv == depv) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
