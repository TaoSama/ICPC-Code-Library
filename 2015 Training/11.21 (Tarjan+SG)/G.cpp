//
//  Created by TaoSama on 2015-11-24
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
const int M = 2e5 + 10;

int n, m;
struct Edge {
    int v, nxt, c;
} edge[M], raw[M];
int head[N], rawHead[N], cnt;

void addRawEdge(int u, int v, int c) {
    raw[cnt] = (Edge) {v, rawHead[u], c};
    rawHead[u] = cnt++;
    raw[cnt] = (Edge) {u, rawHead[v], c};
    rawHead[v] = cnt++;
}

void addEdge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, head[u], c};
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

int ans, dp[N][2]; //0->minimum 1->minor

void dfs(int u, int f) {
    dp[u][0] = dp[u][1] = INF;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dfs(v, u);
        dp[u][1] = min(dp[u][1], dp[v][0]);
        dp[u][1] = min(dp[u][1], edge[i].c);
        if(dp[u][1] < dp[u][0]) swap(dp[u][1], dp[u][0]);
    }
    ans = min(ans, dp[u][1]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0; memset(rawHead, -1, sizeof rawHead);
        while(m--) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            addRawEdge(u, v, c);
        }
        init();
        tarjan(1, -1);

        cnt = 0; memset(head, -1, sizeof head);
        int a, b, minE = INF;
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j = rawHead[i]; ~j; j = raw[j].nxt) {
                int v = id[raw[j].v];
                if(u == v) continue;
                addEdge(u, v, raw[j].c);
                if(raw[j].c < minE) {
                    minE = raw[j].c;
                    a = u, b = v;
                }
            }
        }

        ans = INF;
        dfs(a, b);
        dfs(b, a);
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
