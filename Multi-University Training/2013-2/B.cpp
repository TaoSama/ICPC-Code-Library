//
//  Created by TaoSama on 2016-02-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e6 + 10;

int n, m;

struct Edge {
    int v, nxt;
} edge[M], raw[M];
int head[N], rawHead[N], cnt;

void addRawEdge(int u, int v) {
    raw[cnt] = (Edge) {v, rawHead[u]};
    rawHead[u] = cnt++;
    raw[cnt] = (Edge) {u, rawHead[v]};
    rawHead[v] = cnt++;
}

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

int dfn[N], low[N], in[N], id[N], bcc, dfsNum;
int stk[N], top;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int i = rawHead[u]; ~i; i = raw[i].nxt) {
        int v = raw[i].v;
        if(i == (f ^ 1)) continue;
        if(!dfn[v]) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
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

pair<int, int> diameter;

void dfs(int u, int f, int d) {
    diameter = max(diameter, {d, u});
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dfs(v, u, d + 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        cnt = 0; memset(rawHead, -1, sizeof rawHead);
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            addRawEdge(u, v);
        }
        init();
        tarjan(1, -1);

        cnt = 0; memset(head, -1, sizeof head);
        int treeEdge = 0;
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j = rawHead[i]; ~j; j = raw[j].nxt) {
                int v = id[raw[j].v];
                if(u == v) continue;
                ++treeEdge;
                addEdge(u, v);
            }
        }
        treeEdge >>= 1;

        diameter = { -1, -1};
        dfs(1, -1, 0);
        dfs(diameter.second, -1, 0);

        printf("%d\n", treeEdge - diameter.first);
    }
    return 0;
}

