//
//  Created by TaoSama on 2015-11-08
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

int n, q, s;
int vs[N << 1], es[N << 1], dep[N << 1], first[N], dfsNum;

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

struct BIT {
    int n, b[N << 1];
    void init(int _n) {n = _n, memset(b, 0, sizeof b);}
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit;

struct Edge {
    int id, v, c;
};
int c[N];
vector<Edge> G[N];

void dfs(int u, int f, int d) {
    vs[++dfsNum] = u;
    dep[dfsNum] = d;
    first[u] = dfsNum;
    for(int i = 0; i < G[u].size(); ++i) {
        Edge &e = G[u][i];
        if(e.v == f) continue;
        es[2 * e.id - 1] = dfsNum; //记录bit中存的边的dfsNum
//        printf("dfsNum: %d c: %d\n", dfsNum, e.c);
        bit.add(dfsNum, e.c); //向叶子为+
        dfs(e.v, u, d + 1);
        vs[++dfsNum] = u;
        dep[dfsNum] = d;
        es[2 * e.id] = dfsNum;
        bit.add(dfsNum, -e.c); //向根为-
//        printf("dfsNum: %d c: %d\n", dfsNum, -e.c);
    }
}

void init() {
    dfsNum = 0;
    bit.init(2 * (n - 1)); //边数*2
    dfs(1, -1, 0);
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

    while(scanf("%d%d%d", &n, &q, &s) == 3) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d%d", &u, &v, c + i);
            G[u].push_back((Edge) {i, v, c[i]});
            G[v].push_back((Edge) {i, u, c[i]});
        }
        init();
        while(q--) {
            int op; scanf("%d", &op);
            if(op) {
                int i, w; scanf("%d%d", &i, &w);
                bit.add(es[2 * i - 1], w - c[i]);
                bit.add(es[2 * i], c[i] - w);
                c[i] = w;
            } else {
                int v; scanf("%d", &v);
                int _lca = lca(s, v);
//              printf("s: %d v: %d lca: %d\n", s, v, _lca);
//              printf("first[s]: %d first[v]: %d first[lca]: %d\n", first[s], first[v], first[_lca]);
//              printf("1: %d 2: %d 3: %d\n", bit.sum(first[s]), bit.sum(first[v]), bit.sum(first[_lca]));
                printf("%d\n", bit.sum(first[s] - 1) + bit.sum(first[v] - 1)
                       - 2 * bit.sum(first[_lca] - 1));
                s = v;
            }
        }
    }
    return 0;
}
