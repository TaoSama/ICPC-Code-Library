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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * N;

int n;

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

int dfn[N], low[N], cut[N], dfsNum;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dfsNum;
    int son = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        if(!dfn[v]) {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) cut[u] = true;
        } else low[u] = min(low[u], dfn[v]);
    }
    if(f < 0 && son == 1) cut[u] = false;
}

void init() {
    dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
    memset(cut, false, sizeof cut);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        cnt = 0; memset(head, -1, sizeof head);
        int u, v;
        while(scanf("%d", &u) && u) {
            while(getchar() != '\n') {
                scanf("%d", &v);
                addEdge(u, v);
            }
        }
        init();
        tarjan(1, -1);
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += cut[i];
        printf("%d\n", ans);
    }
    return 0;
}
