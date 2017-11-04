//
//  Created by TaoSama on 2017-03-21
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N];

// Euler Sequence & RMQ(ST)
vector<int> G[N];
int vs[N << 1], dep[N << 1], first[N], dfsNum;

void dfs(int u, int f, int d) {
    vs[++dfsNum] = u;
    dep[dfsNum] = d;
    first[u] = dfsNum;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(v == f) continue;
        dfs(v, u, d + 1);
        vs[++dfsNum] = u;
        dep[dfsNum] = d;
    }
}

inline int getMin(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}

struct SparseTable {
    int dp[20][N << 1];
    void init(int n) {
        for(int i = 1; i <= n; ++i) dp[0][i] = i;
        for(int i = 1; (1 << i) <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                dp[i][j] = getMin(dp[i - 1][j], dp[i - 1][j + (1 << i - 1)]);
    }
    int RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return getMin(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
} st;

inline int lca(int u, int v) {
    if(first[u] > first[v]) swap(u, v);
    int idx = st.RMQ(first[u], first[v]);
    return vs[idx];
}

inline int dist(int u, int v) {
    return dep[first[u]] + dep[first[v]] - 2 * dep[first[lca(u, v)]];
}

void init() {
    dfsNum = 0;
    dfs(1, -1, 0);
    st.init(2 * n - 1);
}

struct D {
    int u, v, d;
    D(int u, int v): u(u), v(v), d(dist(u, v)) {}
    bool operator<(const D& r) const {
        return d < r.d;
    }
    friend D operator+(const D& A, const D& B) {
        return max({A, B, D(A.u, B.u), D(A.u, B.v), D(A.v, B.u), D(A.v, B.v)});
    }
    void see() {
        pr(u); pr(v); prln(d);
    }
};
vector<D> ds[N / 10 + 10];

int timStp = 1, vis[N];
void getDiameter(int u, int fa, int d, pair<int, int>& diameter) {
    vis[u] = timStp;
    diameter = max(diameter, {d, u});
    for(int v : G[u]) {
        if(v == fa || a[v] != a[u]) continue;
        getDiameter(v, u, d + 1, diameter);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        init();
        for(int i = 1; i <= m; ++i) ds[i].clear();
        ++timStp;
        for(int i = 1; i <= n; ++i) {
            if(vis[i] == timStp) continue;
            pair<int, int> diameter = { -1, -1};
            getDiameter(i, -1, 0, diameter);
            int u = diameter.second;
            getDiameter(u, -1, 0, diameter);
            int v = diameter.second;
            ds[a[i]].push_back(D(i, u) + D(u, v));
        }

        for(int i = 1; i <= m; ++i) {
            D ans = ds[i].front();
            for(auto& d : ds[i]) ans = ans + d;
            printf("%d\n", ans.d);
        }

    }

    return 0;
}
