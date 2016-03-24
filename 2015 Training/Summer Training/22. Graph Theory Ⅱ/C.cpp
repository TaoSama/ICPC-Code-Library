//
//  Created by TaoSama on 2015-08-17
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

struct Edge {
    int to, cap, rev;
};

vector<Edge> G[205];
bool vis[205];

void add_edge(int u, int v, int c) {
    G[u].push_back((Edge {v, c, G[v].size()}));
    G[v].push_back((Edge) {u, 0, G[u].size() - 1}); //rev capacity is zero
}

int dfs(int u, int t, int f) {
    if(u == t) return f;
    vis[u] = true;  //mark the vertex
    for(int i = 0; i < G[u].size(); ++i) {
        Edge &e = G[u][i];
        if(!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    int flow = 0;
    while(true) {
        memset(vis, false, sizeof vis); //remember to clear
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
    return -1;
}

int n, m;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &m, &n) == 2) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
        }
        printf("%d\n", maxFlow(1, n));
    }
    return 0;
}
