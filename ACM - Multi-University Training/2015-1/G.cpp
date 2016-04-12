//
//  Created by TaoSama on 2016-03-30
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 2e5 + 10;

struct Edge {
    int v, nxt, cap;
} edge[M], raw[M];
int head[N], cnt;

int rawHead[N], rawCnt;
void addRawEdge(int u, int v, int c) {
    raw[rawCnt] = {v, rawHead[u], c};
    rawHead[u] = rawCnt++;
}

void addEdge(int u, int v, int c) {
    edge[cnt] = {v, head[u], c};
    head[u] = cnt++;
}

void addDouble(int u, int v, int c1, int c2 = 0) {
    addEdge(u, v, c1);
    addEdge(v, u, c2);
}

int lev[N], cur[N];
bool bfs(int s, int t) {
    queue<int> q;
    memset(lev, 0, sizeof lev);
    q.push(s);  lev[s] = 1;
    while(q.size() && !lev[t]) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(edge[i].cap > 0 && !lev[v]) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
    return lev[t];
}

int dfs(int u, int t, int delta) {
    if(u == t || !delta) return delta;
    int ret = 0;
    for(int i = cur[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(edge[i].cap > 0 && lev[v] == lev[u] + 1) {
            int d = dfs(v, t, min(delta, edge[i].cap));
            cur[u] = i;
            ret += d; delta -= d;
            edge[i].cap -= d;
            edge[i ^ 1].cap += d;

            if(delta == 0) return ret;
        }
    }
    lev[u] = 0;
    return ret;
}

int dinic(int s, int t) {
    int ret = 0;
    while(bfs(s, t)) {
        for(int i = s; i <= t; ++i) cur[i] = head[i];
        ret += dfs(s, t, INF);
    }
    return ret;
}

int n, m;

int d[N]; bool in[N];
int spfa(Edge* edge, int* head, bool origin) {
    queue<int> q; q.push(1);
    memset(d, 0x3f, sizeof d);
    memset(in, 0, sizeof in);
    d[1] = 0; in[1] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(!origin && !edge[i].cap) continue;
            if(d[v] > d[u] + edge[i].cap) {
                d[v] = d[u] + edge[i].cap;
                if(!in[v]) {
                    in[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return d[n];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        rawCnt = 0; memset(rawHead, -1, sizeof rawHead);
        for(int i = 1; i <= m; ++i) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            addRawEdge(u, v, w);
            addRawEdge(v, u, w);
        }

        spfa(raw, rawHead, true);

        cnt = 0; memset(head, -1, sizeof head);
        for(int u = 1; u <= n; ++u) {
            for(int i = rawHead[u]; ~i; i = raw[i].nxt) {
                int v = raw[i].v;
                if(d[v] == d[u] + raw[i].cap)
                    addDouble(u, v, 1);
            }
        }

        int maxv = m - spfa(edge, head, false);
        int minv = dinic(1, n);
        printf("%d %d\n", minv,  maxv);
    }
}
