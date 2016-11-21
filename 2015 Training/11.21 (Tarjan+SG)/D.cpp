//
//  Created by TaoSama on 2015-11-21
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e4 + 10;

int n, m;

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

int dfn[N], low[N], in[N], id[N], bcc, dfsNum;
int stk[N], top;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
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
    cnt = 0;
    memset(head, -1, sizeof head);
}

int deg[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        init();
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i, -1);

        memset(deg, 0, sizeof deg);
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j = head[i]; ~j; j = edge[j].nxt) {
                int v = id[edge[j].v];
                if(u == v) continue;
                ++deg[u]; ++deg[v];
            }
        }
        int leaf = 0;
        //each vertex has been counted 2 times
        for(int i = 1; i <= bcc; ++i) leaf += deg[i] == 2;
        printf("%d\n", leaf + 1 >> 1);
    }
    return 0;
}
