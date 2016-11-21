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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 4e4 + 10;

int n, m, val[N], w[N];
struct Edge {
    int v, nxt;
} raw[M], edge[N << 1];
int headRaw[N], headNew[N], cnt;

void addRawEdge(int u, int v) {
    raw[cnt] = (Edge) {v, headRaw[u]};
    headRaw[u] = cnt++;
    raw[cnt] = (Edge) {u, headRaw[v]};
    headRaw[v] = cnt++;
}

void addNewEdge(int u, int v) {
    edge[cnt] = (Edge) {v, headNew[u]};
    headNew[u] = cnt++;
//  edge[cnt] = (Edge){u, headNew[v]};
//  headNew[v] = cnt++;
}

int dfn[N], low[N], in[N], id[N], bcc, dfsNum;
int stk[N], top;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    int first = true;
    for(int i = headRaw[u]; ~i; i = raw[i].nxt) {
        int v = raw[i].v;
        if(v == f && first) {first = false; continue;}
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        w[++bcc] = 0;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = bcc;
            w[bcc] += val[v];
            if(v == u) break;
        }
    }
}

void init() {
    bcc = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
}

int sum, dp[N][2]; //0dif 1subtree-sum

void dfs(int u, int f) {
    dp[u][0] = INF, dp[u][1] = w[u];
    for(int i = headNew[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dfs(v, u);
        dp[u][1] += dp[v][1];
    }
    if(~f) dp[u][0] = min(dp[u][0], abs(sum - 2 * dp[u][1]));
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        init();
        sum = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", val + i);
            sum += val[i];
        }

        cnt = 0; memset(headRaw, -1, sizeof headRaw);
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            addRawEdge(u, v);
        }

        tarjan(1, -1);
        if(bcc == 1) {puts("impossible"); continue;} //--

        cnt = 0; memset(headNew, -1, sizeof headNew);
        for(int i = 0; i < n; ++i) {
            int u = id[i];
            for(int j = headRaw[i]; ~j; j = raw[j].nxt) {
                int v = id[raw[j].v];
                if(u == v) continue;
                addNewEdge(u, v);
            }
        }

        dfs(1, -1);
        int ans = INF;
        for(int i = 1; i <= bcc; ++i) ans = min(ans, dp[i][0]);
        printf("%d\n", ans);
    }
    return 0;
}
