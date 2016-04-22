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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, ans[N];
int maxw[N], minw[N], up[N], down[N];
int cnt;

struct Edge {
    int v, nxt;
} E[N];
int headE[N];

void addEdge(int u, int v) {
    E[cnt] = (Edge) {v, headE[u]};
    headE[u] = cnt++;
    E[cnt] = (Edge) {u, headE[v]};
    headE[v] = cnt++;
}

struct Query {
    int u, v, nxt;
} Q[N];
int headQ[N];

void addQuery(int u, int v) {
    Q[cnt] = (Query) {u, v, headQ[u]};
    headQ[u] = cnt++;
    Q[cnt] = (Query) {v, u, headQ[v]};
    headQ[v] = cnt++;
}

struct LCA {
    int id, nxt;
} L[N];
int headL[N];

void addLCA(int lca, int id) {
    L[cnt] = (LCA) {id, headL[lca]};
    headL[lca] = cnt++;
}

int ancestor[N], vis[N];

int find(int u) {
    if(ancestor[u] == u) return u;
    int f = ancestor[u];
    ancestor[u] = find(ancestor[u]);
    up[u] = max(max(up[u], up[f]), maxw[f] - minw[u]);
    down[u] = max(max(down[u], down[f]), maxw[u] - minw[f]);
    maxw[u] = max(maxw[u], maxw[f]);
    minw[u] = min(minw[u], minw[f]);
    return ancestor[u];
}

void tarjan(int u) {
    vis[u] = true;
    ancestor[u] = u;
    for(int i = headE[u]; ~i; i = E[i].nxt) {
        int v = E[i].v;
        if(vis[v]) continue;
        tarjan(v);
        ancestor[v] = u;
    }
    for(int i = headQ[u]; ~i; i = Q[i].nxt) {
        int v = Q[i].v;
        if(!vis[v]) continue;
        int lca = find(v);
        addLCA(lca, i);
    }
    for(int i = headL[u]; ~i; i = L[i].nxt) {
        int id = L[i].id;
        if(id & 1) id ^= 1;
        int u = Q[id].u, v = Q[id].v;
        find(u); find(v); //there's one path to lca hasn't been updated
        ans[id >> 1] = max(max(up[u], down[v]), maxw[v] - minw[u]);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", minw + i);
            maxw[i] = minw[i];
            up[i] = down[i] = 0;
        }
        cnt = 0; memset(headE, -1, sizeof headE);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        scanf("%d", &q);
        cnt = 0; memset(headQ, -1, sizeof headQ);
        for(int i = 1; i <= q; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addQuery(u, v);
        }

        cnt = 0; memset(headL, -1, sizeof headL);
        memset(vis, false, sizeof vis);
        tarjan(1);
        for(int i = 0; i < q; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
