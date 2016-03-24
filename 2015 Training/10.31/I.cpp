//
//  Created by TaoSama on 2015-11-03
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int n, m;

struct Edge {
    int v, nxt, c;
} edges[M];
int head[N], cnt;

void add_edge(int u, int v, int c) {
    edges[cnt] = (Edge) {v, head[u], c};
    head[u] = cnt++;
}

int in[N], id[N], dfn[N], low[N], stk[N], dfsNum, top, scc;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    in[u] = true;
    stk[++top] = u;
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++scc;
        while(true) {
            int v = stk[top--];
            id[v] = scc;
            in[v] = false;
            if(v == u) break;
        }
    }
}

void init() {
    scc = cnt = top = dfsNum = 0;
    memset(head, -1, sizeof head);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(in, 0, sizeof in);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        init();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
        }
        for(int i = 0; i < n; ++i)
            if(!dfn[i]) tarjan(i);

        memset(in, 0x3f, sizeof in);
        for(int i = 0; i < n; ++i) {
            int u = id[i];
            for(int j = head[i]; ~j; j = edges[j].nxt) {
                int v = id[edges[j].v];
                if(u != v) in[v] = min(in[v], edges[j].c);
            }
        }
        int ans = 0;
        //no "in" edge of root, in[root] = INF;
        for(int i = 1; i <= scc; ++i)
            if(in[i] != INF) ans += in[i];
        printf("%d\n", ans);
    }
    return 0;
}
