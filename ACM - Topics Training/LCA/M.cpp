//
//  Created by TaoSama on 2015-11-09
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

int n;

const int LOG = 15;
int p[LOG][N], dep[N], dp[N];

struct Edge {
    int v, c, nxt;
} edge[N << 1];
int head[N], cnt;

void add_edge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, c, head[u]};
    head[u] = cnt++;
}

void dfs(int u, int f, int d) {
    dep[u] = d;
    p[0][u] = f;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dp[v] = dp[u] + edge[i].c;
        dfs(v, u, d + 1);
    }
}

void build() {
    dfs(1, -1, 0);
    for(int i = 0; i + 1 < LOG; ++i)
        for(int v = 1; v <= n; ++v)
            if(p[i][v] < 0) p[i + 1][v] = -1;
            else p[i + 1][v] = p[i][p[i][v]];
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < LOG; ++i)
        if(dep[v] - dep[u] >> i & 1)
            v = p[i][v];
    if(u == v) return u;
    for(int i = LOG - 1; ~i; --i) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

int get(int u, int k) {
    for(int i = 0; i < LOG; ++i)
        if(k >> i & 1) u = p[i][u], k ^= 1 << i;
    return u;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        build();
        while(true) {
            char op[5]; scanf("%s", op);
            if(op[1] == 'O') break;
            int u, v; scanf("%d%d", &u, &v);
            if(op[1] == 'I') {
                int _lca = lca(u, v);
                printf("%d\n", dp[u] + dp[v] - 2 * dp[_lca]);
            } else {
                int k; scanf("%d", &k);
                --k;
                int _lca = lca(u, v);
                int l = dep[u] - dep[_lca];
                int d = dep[u] + dep[v] - 2 * dep[_lca];
                if(k == 0) printf("%d\n", u);
                else if(k == l) printf("%d\n", _lca);
                else if(k < l) printf("%d\n", get(u, k));
                else if(k == d) printf("%d\n", v);
                else {
                    k = d - k;
                    printf("%d\n", get(v, k));
                }
            }
        }
    }
    return 0;
}
