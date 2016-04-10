//
//  Created by TaoSama on 2016-04-10
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 10;

struct Edge {
    int v, nxt, cost, cap;
} edge[M];
int head[N], cnt;

void addEdge(int u, int v, int c, int w1, int w2 = 0) {
    edge[cnt] = {v, head[u], c, w1};
    head[u] = cnt++;
    edge[cnt] = {u, head[v], -c, w2};
    head[v] = cnt++;
}

int in[N], d[N], delta[N], pre[N];
bool spfa(int s, int t) {
    queue<int> q; q.push(s);
    for(int i = s; i <= t; ++i) d[i] = INF, in[i] = false;
    delta[s] = INF; d[s] = 0; in[s] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v, cap = edge[i].cap, cost = edge[i].cost;
            if(cap > 0 && d[v] > d[u] + cost) {
                delta[v] = min(delta[u], cap);
                d[v] = d[u] + cost;
                pre[v] = i;
                if(!in[v]) q.push(v), in[v] = true;
            }
        }
    }
    return d[t] != INF;
}

void minCostMaxFlow(int s, int t, int& flow, int& cost) {
    while(spfa(s, t)) {
        flow += delta[t];
        cost += d[t] * delta[t];
        for(int i, u = t; u != s; u = edge[i ^ 1].v) {
            i = pre[u];
            edge[i].cap -= delta[t];
            edge[i ^ 1].cap += delta[t];
        }
    }
}

int n, g[N][N];
bool lft[N], girl[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        char buf[N];
        scanf("%s", buf + 1);
        for(int i = 1; i <= n; ++i)
            lft[i] = buf[i] == '0';
        scanf("%s", buf + 1);
        for(int i = 1; i <= n; ++i)
            girl[i] = buf[i] == '0';

        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; ++i) {
            if(!lft[i]) continue;
            for(int j = 1; j <= n; ++j) {
                if(lft[j]) continue;
                g[i][j] = girl[i] + girl[j] + 1;
            }
        }
        for(int i = 1; i <= n; ++i) {
            int cnt; scanf("%d", &cnt);
            while(cnt--) {
                int x; scanf("%d", &x);
                if(lft[i] && !lft[x]) g[i][x] = 0;
            }
        }

        cnt = 0; memset(head, -1, sizeof head);

        int s = 0, t = n + 1;
        for(int i = 1; i <= n; ++i) {
            if(lft[i]) addEdge(s, i, 0, 1);
            if(!lft[i]) addEdge(i, t, 0, 1);
            for(int j = 1; j <= n; ++j) {
                if(!g[i][j]) continue;
                addEdge(i, j, g[i][j], 1);
            }
        }

        int flow = 0, cost = 0;
        minCostMaxFlow(s, t, flow, cost);

        printf("%d %d\n", flow, cost - flow);
        for(int i = 1; i <= n; ++i) {
            if(!lft[i]) continue;
            for(int j = head[i]; ~j; j = edge[j].nxt) {
                int v = edge[j].v;
                if(!lft[v] && edge[j ^ 1].cap) printf("%d %d\n", i, v);
            }
        }
    }
    return 0;
}
