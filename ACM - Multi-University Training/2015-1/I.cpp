//
//  Created by TaoSama on 2016-04-26
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;

struct Edge {
    int v, c;
};
vector<Edge> G[N];

const int LOG = 17;
int dfn[N], dfsNum;
int dep[N], dis[N], p[LOG][N];

void dfs(int u, int fa) {
    dfn[u] = ++dfsNum;
    p[0][u] = fa;
    for(int i = 1; i < LOG; ++i) p[i][u] = p[i - 1][p[i - 1][u]];
    for(Edge& e : G[u]) {
        int v = e.v, c = e.c;
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dis[v] = dis[u] + c;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 0; i < LOG; ++i)
        if(dep[v] - dep[u] >> i & 1) v = p[i][v];
    if(u == v) return u;
    for(int i = LOG - 1; ~i; --i)
        if(p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}

//dis(u, x, y) = (dis(u, x) + dis(u, y) - dis(x, y)) / 2
//dis(u)+dis(x)-2dis(lca(u,x)) + dis(u)+dis(y)-2dis(lca(u,y))
//-dis(x)-dis(y)+2*dis(lca(x,y))

//vertex to chain
int get(int u, int x, int y) {
    return dis[u] - dis[lca(u, x)] - dis[lca(u, y)] + dis[lca(x, y)];
}

int gao(int u, set<pair<int, int> >& s) {
    if(!s.size()) return 0;

    int x, y;
    auto iter = s.lower_bound({dfn[u], u});
    if(iter == s.end() || iter == s.begin()) {
        x = s.begin()->second;
        y = s.rbegin()->second;
    } else {
        x = iter->second;
        --iter;
        y = iter->second;
    }
    return get(u, x, y);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }

        dfsNum = 0;
        dfs(1, 0);

        static int kase = 0;
        printf("Case #%d:\n", ++kase);

        set<pair<int, int> > s;
        int ans = 0;
        while(q--) {
            int op, u; scanf("%d%d", &op, &u);
            if(op == 1) {
                if(!s.count({dfn[u], u})) {
                    ans += gao(u, s);
                    s.insert({dfn[u], u});
                }
            } else {
                if(s.count({dfn[u], u})) {
                    s.erase({dfn[u], u});
                    ans -= gao(u, s);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
