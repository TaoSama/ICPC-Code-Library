//
//  Created by TaoSama on 2016-03-31
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m;
vector<int> G[N], T[N];
int dfn[N], low[N], in[N], id[N], bcc, dfsNum;
int stk[N], top;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int& v : G[u]) {
        if(v == f) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++bcc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = bcc;
            if(v == u) break;
        }
    }
}

void init() {
    bcc = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
}

bool vis[N];
void dfs(int u, bool& ok, vector<int>& sz) {
    vis[u] = true;
    ok |= (sz[u] > 1);
    for(int v : T[u]) {
        if(vis[v]) continue;
        dfs(v, ok, sz);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    init();
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i, -1);

    vector<int> sz(N, 0);
    for(int i = 1; i <= n; ++i) sz[id[i]]++;

    for(int i = 1; i <= n; ++i) {
        int u = id[i];
        for(int& j : G[i]) {
            int v = id[j];
            T[u].push_back(v);
        }
    }

    int ans = 0;
    for(int i = 1; i <= bcc; ++i) {
        if(vis[i]) continue;
        bool ok = false;
        dfs(i, ok, sz);
        ans += !ok;
    }
    printf("%d\n", ans);
    return 0;
}
