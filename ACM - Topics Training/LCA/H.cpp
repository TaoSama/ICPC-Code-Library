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

int n, m, q;

struct Edge {
    int v, c, nxt;
} edge[N << 1];
int head[N], cnt;

void add_edge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, c, head[u]};
    head[u] = cnt++;
}

int vs[N << 1], dep[N << 1], first[N], dp[N], id[N], dfsNum, cc;

int getMin(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}

struct SparseTable {
    int dp[20][N << 1];
    void init(int n) {
        for(int i = 1; i <= n; ++i) dp[0][i] = i;
        for(int i = 1; 1 << i <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                dp[i][j] = getMin(dp[i - 1][j], dp[i - 1][j + (1 << i - 1)]);
    }
    int RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return getMin(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
} st;

void dfs(int u, int f, int d) {
    vs[++dfsNum] = u;
    dep[dfsNum] = d;
    first[u] = dfsNum;
    id[u] = cc;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;
        dp[v] = dp[u] + edge[i].c;
        dfs(v, u, d + 1);
        vs[++dfsNum] = u;
        dep[dfsNum] = d;
    }
}

void build() {
    dfsNum = cc = 0;
    memset(id, 0, sizeof id);
    for(int i = 1; i <= n; ++i) {
        ++cc;
        if(!id[i]) dp[i] = 0, dfs(i, -1, 0);
    }
    st.init(2 * n - 1);
}

int lca(int u, int v) {
    if(first[u] > first[v]) swap(u, v);
    int idx = st.RMQ(first[u], first[v]);
    return vs[idx];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &q) == 3) {
        cnt = 0; memset(head, -1, sizeof head);
        while(m--) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        build();
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            if(id[u] != id[v]) puts("Not connected");
            else  printf("%d\n", dp[u] + dp[v] - 2 * dp[lca(u, v)]);
        }
    }
    return 0;
}
