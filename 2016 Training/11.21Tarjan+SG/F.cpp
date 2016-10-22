//
//  Created by TaoSama on 2015-11-22
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
const int M = 4e5 + 10;

int n, m, q;

//edge
struct Edge {
    int v, nxt;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
    edge[cnt] = (Edge) {u, head[v]};
    head[v] = cnt++;
}

//dsu
int par[N];
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    par[v] = u;
    return true;
}

//tarjan
int dfn[N], low[N], pre[N], dfsNum;
int stk[N], top, bridge;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(i == (f ^ 1)) continue;
        if(!dfn[v]) {
            pre[v] = u;
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) ++bridge;
            else unite(u, v);
        } else low[u] = min(low[u], dfn[v]);
    }
}

void lca(int u, int v) {
    if(find(u) == find(v)) return;

    if(dfn[u] > dfn[v]) swap(u, v);
    while(dfn[v] > dfn[u]) {
        if(unite(pre[v], v)) --bridge;
        v = pre[v];
    }
    while(u != v) {
        if(unite(pre[u], u)) --bridge;
        u = pre[u];
    }
}

void init() {
    bridge = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
    cnt = 0; memset(head, -1, sizeof head);
    for(int i = 1; i <= n; ++i) par[i] = i; //dsu init
}

int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        init();
        while(m--) {
            int u = read(), v = read();
            addEdge(u, v);
        }
        tarjan(1, -1);

        q = read();
        printf("Case %d:\n", ++kase);
        while(q--) {
            int u = read(), v = read();
            lca(u, v);
            printf("%d\n", bridge);
        }
        puts("");
    }
    return 0;
}
