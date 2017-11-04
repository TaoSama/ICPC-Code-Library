//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
vector<int> G[N];

const int LOG = 17;
int dep[N], p[LOG][N];

void dfs(int u, int fa) {
    p[0][u] = fa;
    for(int i = 1; i < LOG; ++i) p[i][u] = p[i - 1][p[i - 1][u]];
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < LOG; ++i)
        if(dep[v] - dep[u] >> i & 1) v = p[i][v];
    if(u == v) return u;
    for(int i = LOG - 1; ~i; --i)
        if(p[i][u] != p[i][v]) u = p[i][u], v = p[i][v];
    return p[0][u];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 0);
        while(q--) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            int dx = (dep[c] + dis(b, c) - dep[a]) / 2;
            prln(dx);
            puts(dx < dep[c] ? "YES" : "NO");
        }
    }

    return 0;
}
