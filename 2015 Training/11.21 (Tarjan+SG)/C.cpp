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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 5e4 + 10;

int n, m;
struct Edge {
    int v, nxt;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

int dfn[N], low[N], in[N], id[N], scc, dfsNum;
int stk[N], top;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++scc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = scc;
            if(v == u) break;
        }
    }
}

void init() {
    scc = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
}

int inDeg[N], outDeg[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        cnt = 0; memset(head, -1, sizeof head);
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        init();
        for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
        if(scc == 1) {puts("0"); continue;} //已经连通

        memset(inDeg, 0, sizeof inDeg);
        memset(outDeg, 0, sizeof outDeg);
        for(int j = 1; j <= n; ++j) {
            int u = id[j];
            for(int i = head[j]; ~i; i = edge[i].nxt) {
                int v = edge[i].v;
                v = id[v];
                if(u == v) continue;
                ++outDeg[u]; ++inDeg[v];
            }
        }

        int root = 0, leaf = 0;
        for(int i = 1; i <= scc; ++i) {
            if(inDeg[i] == 0) ++root;
            if(outDeg[i] == 0) ++leaf;
        }
        printf("%d\n", max(root, leaf));
    }
    return 0;
}
