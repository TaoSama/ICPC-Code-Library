//
//  Created by TaoSama on 2015-11-08
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

int n, dep[N], p[20][N];
bool vis[N];
vector<int> G[N];

void dfs(int u, int f, int d) {
    p[0][u] = f;
    dep[u] = d;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == f) continue;
        dfs(v, u, d + 1);
    }
}

void init() {
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) {dfs(i, -1, 0); break;}
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
    for(int i = 17; ~i; --i) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
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
        for(int i = 1; i <= n; ++i) G[i].clear();
        memset(vis, 0, sizeof vis);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            vis[v] = true;
        }
        init();
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}
