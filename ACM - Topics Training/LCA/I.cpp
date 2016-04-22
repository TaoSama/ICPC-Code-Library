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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, dp[N];

struct Edge {
    int v, nxt;
} E[N << 1];
int headE[N], cnt;

void addEdge(int u, int v) {
    E[cnt] = (Edge) {v, headE[u]};
    headE[u] = cnt++;
    E[cnt] = (Edge) {u, headE[v]};
    headE[v] = cnt++;
}

struct Query {
    int v, nxt, id;
} Q[N << 1];
int headQ[N];

void addQuery(int u, int v, int id) {
    Q[cnt] = (Query) {v, headQ[u], id};
    headQ[u] = cnt++;
    Q[cnt] = (Query) {u, headQ[v], id};
    headQ[v] = cnt++;
}

bool vis[N], checked[N];
int ancestor[N];

int find(int x) {
    return ancestor[x] = ancestor[x] == x ? x : find(ancestor[x]);
}

void tarjan(int u) {
    ancestor[u] = u;
    vis[u] = true;
    for(int i = headE[u]; ~i; i = E[i].nxt) {
        int v = E[i].v;
        if(vis[v]) continue;
        tarjan(v);
        ancestor[v] = u;
    }
    for(int i = headQ[u]; ~i; i = Q[i].nxt) {
        int v = Q[i].v, id = Q[i].id;
        if(!vis[v]) continue;
        if(checked[id]) continue;
        checked[id] = true;
        int lca = find(v);
        dp[lca] -= 2;
    }
}

void dfs(int u, int f) {
    for(int i = headE[u]; ~i; i = E[i].nxt) {
        int v = E[i].v;
        if(v == f) continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0; memset(headE, -1, sizeof headE);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        cnt = 0; memset(headQ, -1, sizeof headQ);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addQuery(u, v, i);
            ++dp[u]; ++dp[v];
        }

        memset(vis, false, sizeof vis);
        memset(checked, false, sizeof checked);
        tarjan(1);

        dfs(1, -1);

        int ans = 0;
        for(int i = 2; i <= n; ++i) {
            if(dp[i] == 0) ans += m;
            else if(dp[i] == 1) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
